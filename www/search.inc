<?

include( "template.inc" );
include( "crux_secrets.php" );
?>

<form method="get" action="index.php">
        Search in
        <select name="field">
            <?
                foreach ( array( "Name", "Description", "Maintainer",
                "Packager", "Packager/Maintainer", /* "File", */ "Group" ) as $opt ) {
                    $s = "";
                    if ( $opt == $field ) {
                        $s = "selected";
                    }
                    print "<option $s>$opt</option>";
                }
            ?>
        </select>

        in section
        <select name="section">
            <?
                foreach ( array( "all", "base", "opt", "clc/stable", "clc/unstable" ) as $opt ) {
                    $s = "";
                    if ( $opt == $section ) {
                        $s = "selected";
                    }
                    print "<option $s>$opt</option>";
                }
            ?>
        </select>
        for:
        <input type="text" name="field_value" size="25" value="<? print $field_value?>">
        <input type="hidden" name="p" value="search">
        <input type="Submit" value="search">
 </form>
 <p>
 <a href="<?= $PHP_SELF ?>?field=Name&section=all&field_value=%25&p=search">List all ports</a>
</p>
<?
     
$link = mysql_connect( "db.berlios.de:/tmp/mysql.sock", $db_user, $db_pw )
or die("Could not connect");
mysql_select_db( $db_name ) or die(mysql_error()); 

$value = addslashes( $field_value );

if ( $section != "all" ) {
    $section = addslashes( $section );
    $section = "and section='$section'";
} else {
    $section = "";
}

$portSearch = 1;
if ( !empty( $port ) ) {
    $sql = "select * from ports where name='$port'";
    $result = mysql_query( $sql )  or die("Invalid query: $sql");
    print "<hr>";
    printInfo( $result );
    $sql = 0;
}else if ( empty( $field_value ) ) {
    $sql = 0;
} else if ( $field == "Name" ) {
    $sql = "select * from ports where name like '%".$value."%' $section order by section, name";
    $query = "name containing '" . $value."'";
} else if ( $field == "Packager" ) {
    $sql = "select * from ports where packager like '%".
    $value ."%' $section order by section, name";
    $query = "packager containing '" . $value."'";
} else if ( $field == "Maintainer" ) {
    $sql = "select * from ports where maintainer like '%".
    $value ."%' $section order by section, name";
    $query = "maintainer containing '" . $value."'";
} else if ( $field == "Packager/Maintainer" ) {
    $sql = "select * from ports where (maintainer like '%".
    $value ."%' or packager like '%".
    $value ."%')  $section order by section, name";
    $query = "maintainer containing '" . $value."'";
} else if ( $field == "Description" ) {
    $sql = "select * from ports where description like '%".
    $value ."%' $section order by section, name";
    $query = "description containing '" . $value."'";
} else if ( $field == "File" ) {
    $sql = "select * from files where filename like '%".
    $value."%' $section order by section, portname, filename";
    $query = "file containing '" . $value."'";
    $portSearch = 0;
} else if ( $field == "Group" ) {
    $sql = "select * from ports where portgroup like '%".
    $value ."%' $section order by section, name";
    $query = "description containing '" . $value."'";
} else {
    $sql = 0;
}

if ( $sql ) {
?><hr><?
    $result = mysql_query( $sql )  or die("Invalid query: $sql");

    ?>
    <h3>Search results for <? print $query ?>:</h3>
    <?
    $count = mysql_num_rows( $result );
    if ( $count > 1 ) {
        echo $count . " records found";
    } else if ( $count == 0 ) {
        echo "Sorry, no records found";
    }

    if ( $count > 0 ) {
        echo "<table>";

        if ( $portSearch == 0) {
            printFileRowHeaders();
            printFileRows( $result );
        } else {
            printPortRowHeaders();
            printPortRows( $result );
        }
        
        echo "</table>";
    }
} 
?>
