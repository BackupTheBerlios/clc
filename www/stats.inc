<?

include( "template.inc" );
include( "/home/crux/htdocs/people/jw/clcweb/crux_secrets.php" );

if ( !isset( $count ) ) {
	$count = 10;
}
if ( !isset( $section ) ) {
    $section = "all";
}

$link = mysql_connect( "localhost", $db_user, $db_pw );
mysql_select_db( $db_name );


/* ----------------------------------------- */

?>

<form method="get" action="index.php">
Show only section
<select name="section">
<?
foreach ( array( "all", "base", "opt", "clc/stable", "clc/unstable" ) as $opt )  {
    $s = "";
    if ( $opt == $section ) {
        $s = "selected";
    }
    print "<option $s>$opt</option>";
}
?>
</select>
<input type="hidden" name="p" value="stats">
<input type="Submit" value="Filter">
</form>


<table width="100%">

<tr><td colspan="4"><big>&nbsp;</big></td></tr>
<tr><td colspan="4"><big><b>Latest change</b></big></td></tr> 
<?
    printPortRowHeaders( true );
    $filter = "";
    if ( $section != "all" ) {
            $filter = 'AND section =\'' . $section . '\'';
    }
    $sql = 'SELECT * FROM ports where added <> changed '.$filter.
           ' ORDER BY changed DESC, name LIMIT 0, '.$count;
    $result_changed = mysql_query( $sql );
    $i = printPortRows( $result_changed, true, $i );

?>
<tr><td colspan="4"><big>&nbsp;</big></td></tr>
<tr><td colspan="4"><big><b>Latest additions</b></big></td></tr>
<?

    printPortRowHeaders( true );
    $filter = "";
    if ( $section != "all" ) {
            $filter = 'AND section =\'' . $section . '\'';
    }
    $sql = 'SELECT * FROM ports where added = changed '.$filter.
           ' ORDER BY changed DESC, name LIMIT 0, '.$count;
    $result_add = mysql_query( $sql );
    $i = printPortRows( $result_add, true, $i );
?>

<tr><td colspan="4"><big>&nbsp;</big></td></tr>
<tr><td colspan="4"><big><b>Stats:</b></big></td></tr>
<? printPortStats(); ?>
</td></tr>
</table>
