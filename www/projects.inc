<?
$lp = new LinkPrinter;
$lp->setPage( "projects/" ); 


// TODO: add project -> seperate file
$projects["art"] = "CRUX art";
$projects["apache"] = "the httpd";
$projects["gnome"] = "the GNOME desktop environment";
$projects["httpup"] = "a synchronisation tool for http file repositories";
$projects["kde"] = "the KDE desktop environment";
$projects["ipv6"] = "IPv6 ports";
// $projects["print"] = "Printing related stuff";
// $projects["boot"] = "boot related";
// $projects["nessus"] = "ports for nessus, the network security scanner";

?>

    <h3>Projects</h3>
    We try to support projects related to CRUX if we think they fit our
    philosophy. Currently you can find the following projects here:

    <ul>

    <?
    foreach ($projects as $name => $desc ) {
        print "<li>";
        $lp->printLink( $name, $name . ": " . $desc );
        print "</li>";
    }
?>
    </ul>

<p>
Feel free to contact us if you'd like to place you CRUX related project at CLC
</p>
