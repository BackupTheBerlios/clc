<?
/*
 * CLC web page template
 *
 * 22.09.2002   jw
 */

function printPortStats() {

    $stat_sections = array("total", "base", "opt", "clc/stable", "clc/unstable" );
    foreach ( $stat_sections as $section ) {
        $ssql = " where section='$section'";
        if ( $section == "total" ) {
            $ssql = "";
        }
        $bgcolor = (++$i % 2) ? "#eeeeff" : "ffffff";
        print "<tr bgcolor=\"$bgcolor\">";
        print "<td colspan=\"2\">Number of ports in $section:</td>";
        print "<td colspan=\"2\">";

        $sql = "SELECT COUNT(*) FROM ports $ssql";
        $countResult = mysql_query( $sql );
        $row = mysql_fetch_row( $countResult );
        print $row[0];

        echo "</td></tr>";
    }

}

function encodeEmail( $str ) {
    $str = preg_replace( "/\</", "&lt;", $str );
    $str = preg_replace( "/\>/", "&gt;", $str );
    $str = preg_replace( "/@/", " at ", $str );

    return $str;
}


function removeEmail( $str ) {
    return preg_replace( "/\<.*$/", "", $str );
}

function printFileRowHeaders() 
{
    ?>
    <tr>
        <td><b>port</b></td>
        <td><b>file</b></td>
    </tr>
    <?
}

function printFileRows( $result )
{
    $i = 0;
    while( $row = mysql_fetch_row( $result ) ) {
        /* TODO: escape < and > */
        $bgcolor = ($i % 2) ? "#eeeeff" : "ffffff";
        echo "<tr bgcolor=\"$bgcolor\">";
        echo "<td><a href=\"index.php?p=search&port=$row[1]\">".$row[2]."/".$row[1]."</a></td>";
        echo "<td>".$row[0]."</td>";
        echo "</tr>";
        ++$i;
    }
}

function printPortRowHeaders( $showDate = 0 )
{
    ?>
    <tr>
        <td><b>port</b></td>
        <td><b>version</b></td>
        <td><b>description</b></td>
        <?
        if ( $showDate ) {
            ?><td><b>date</b></td><?
        } else {
            
            ?><td><b>Packager</b></td><?
            ?><td><b>Maintainer</b></td><?
        }
        
        ?>
    </tr>
    <?
}

/** if $showDate is false, packager and maintainer are printed... */
function printPortRows( $result, $showDate = 0, $i=0 )
{
    while( $row = mysql_fetch_row( $result ) ) {
        $bgcolor = ($i % 2) ? "#ffffff" : "eeeeff";
        echo "<tr bgcolor=\"$bgcolor\">";
        echo "<td><a href=\"index.php?p=search&port=$row[0]\">".$row[1]."/".$row[0]."</a></td>";
        echo "<td>".$row[2]."-".$row[3]."</td>";
        echo "<td>".$row[4]."</td>";
        if ( $showDate ) {
            echo "<td>".$row[10]."</td>";
        } else {
            echo "<td>".removeEmail($row[6])."</td>";
            echo "<td>".removeEmail($row[7])."</td>";
        }
        echo "</tr>";
        ++$i;
    }

    return $i;
}

function printInfo( $result )
{
    if ( $row = mysql_fetch_row( $result ) ) {
        echo "<h3>Port information:</h3>";
        echo "<table>"; 
        echo "<tr bgcolor=\"eeeeff\">";
        echo "<td><b>Name:</b></td><td>$row[0]</td></tr><tr>";
        echo "<td><b>Section:</b></td><td>$row[1]</td></tr><tr bgcolor=\"eeeeff\">";
        echo "<td><b>Version:</b></td><td>$row[2]</td></tr><tr>";
        echo "<td><b>Release:</b></td><td>$row[3]</td></tr><tr bgcolor=\"eeeeff\">";
        echo "<td><b>Description:</b></td><td>$row[4]</td></tr><tr>";
        echo "<td><b>URL:</b></td><td><a href=\"$row[5]\">$row[5]</a></td></tr><tr bgcolor=\"eeeeff\">";

        echo "<td><b>Packager:</b></td><td>".encodeEmail($row[6])."$tmp</td></tr><tr>";
        echo "<td><b>Maintainer:</b></td><td>".encodeEmail($row[7])."</td></tr><tr bgcolor=\"eeeeff\">";
        echo "<td><b>Group:</b></td><td><a href=\"http://crux.lugs.ch/projects/$row[8]\">$row[8]</a></td></tr><tr>";
        echo "<td><b>Added:</b></td><td>$row[9]</td></tr><tr bgcolor=\"eeeeff\">";
        echo "<td><b>Changed:</b></td><td>$row[10]</td></tr><tr>";

        echo "<td><b>CVS:</b>";
        if ( $row[1] == "clc/stable" ) {
            $cvsroot = "http://crux.lugs.ch/cgi-bin/cvs/stable/$row[0]/?only_with_tag=STABLE-1_1";
            echo "<td>";
            echo "<a href=\"http://crux.lugs.ch/cgi-bin/cvs/stable/$row[0]/Pkgfile?rev=HEAD&only_with_tag=STABLE-1_1&content-type=text/vnd.viewcvs-markup\">Pkgfile</a>&nbsp;";
            echo "<a href=\"http://crux.lugs.ch/cgi-bin/cvs/stable/$row[0]/.footprint?rev=HEAD&only_with_tag=STABLE-1_1&content-type=text/vnd.viewcvs-markup\">.footprint</a>&nbsp;";
            echo "<a href=\"http://crux.lugs.ch/cgi-bin/cvs/stable/$row[0]/.md5sum?rev=HEAD&only_with_tag=STABLE-1_1&content-type=text/vnd.viewcvs-markup\">.md5sum</a>";
            echo "</td>";
        } else if ( $row[1] == "clc/unstable" ) {
            $cvsroot = "http://crux.lugs.ch/cgi-bin/cvs/unstable/$row[0]/?only_with_tag=UNSTABLE-1_1";
            echo "<td>";
            echo "<a href=\"http://crux.lugs.ch/cgi-bin/cvs/unstable/$row[0]/Pkgfile?rev=HEAD&only_with_tag=STABLE-1_1&content-type=text/vnd.viewcvs-markup\">Pkgfile</a>&nbsp;";
            echo "<a href=\"http://crux.lugs.ch/cgi-bin/cvs/unstable/$row[0]/.footprint?rev=HEAD&only_with_tag=STABLE-1_1&content-type=text/vnd.viewcvs-markup\">.footprint</a>&nbsp;";
            echo "<a href=\"http://crux.lugs.ch/cgi-bin/cvs/unstable/$row[0]/.md5sum?rev=HEAD&only_with_tag=STABLE-1_1&content-type=text/vnd.viewcvs-markup\">.md5sum</a>";
            echo "</td>";
        } else {
            // base and opt
            $cvsroot = "http://www.fukt.bth.se/~per/crux/cvs.cgi/$row[1]/$row[0]/?only_with_tag=STABLE-1_1";
            
            echo "</td><td><a href=\"$cvsroot\">$row[0]</a></td>";
        }
        echo "</tr>";
        echo "</table>";
        ++$i;
    }

    return $i;
}
function printInfoText( $result )
{
    if ( $row = mysql_fetch_row( $result ) ) {
        echo "Name:        $row[0]<br>";
        echo "Collection:  $row[1]<br>";
        echo "Version:     $row[2]-$row[3]<br>";
        echo "Description: $row[4]<br>";
        echo "URL:         $row[5]<br>";
	if ($row[6] != "") {
            echo "Packager:    $row[6]<br>";
	}
        echo "Maintainer:  $row[7]<br>";

	if ($row[8] != "") {
            echo "Group:       $row[8]<br>";
        }
	echo "Added:       $row[9]<br>";
        echo "Changed:     $row[10]<br>";
        ++$i;
    }

    return $i;
}

function print_title( $text ) {
    print "<table width=\"100%\" bgcolor=\"#55aaaa\"><tr><td>" .
        $text . "</td></tr></table>";
}

?>
