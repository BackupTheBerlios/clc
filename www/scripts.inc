<h3>Scripts</h3>

<?

function addScript( $name, $desc, $author ) {
    $baseURL="http://crux.lugs.ch/files/";
    print "<tr><td><a href=\"$baseURL$name\">$name</a></td>";
    print "<td>$desc</td><td>$author</td></tr>";
}
?>

<table>
<?
addScript( "prtrej", "interactive tool to clean up /var/lib/pkg/rejected",
           "Markus Ackermann" );
addScript( "ports-http", "download daily ports from crux.lugs.ch",
           "Daniel Mueller" );
addScript( "prtupdate", "Update outdated ports", "Markus Ackermann" );
addScript( "prtrej", "", "" );
addScript( "orphan.sh", "Find files which are not owner by a package",
           "Johannes Winkelmann" );
?>
</table>