<h3>Docs</h3>

<h4>Internal documentation</h4>
<ul>
<li><a href="doc/pkgstd.html">Package Guidelines</a></li>
<li>CVS HOWTO for CLC Maintainers (
<a href="doc/clc-cvs.html">HTML</a>,
<a href="doc/clc-cvs-2.pdf">PDF</a>
)</li>
</ul>

<?

function docItem( $url, $title, $author ) {
    print "<li><a href=\"$url\">$title</a> ($author)</li>";
}

?>

<h4>Other documents</h4>
<ul>
<?
docItem( "http://crux.nu/doc/handbook.html", "The CRUX Handbook", "Per Lidén");
docItem(  "http://rfhs8012.fh-regensburg.de/~opel/crux/network-setup.php",
          "FTP based setup", "Martin Opel" );
docItem( "http://home.t-online.de/home/juergen.daubert/crux/doc/crux-nfs-install.html",
         "How to install CRUX from a NFS server of your local network",
         "Jürgen Daubert");
docItem( "http://miba.fxnet.hu/crux/loopback-install",
         "Install CRUX from loopback device", "Mikael Bak" );
docItem( "http://crux.lugs.ch/people/martin/firewall.html",
         "Using the CRUX Ports System Behind a Firewall", "Martin Lund" );
docItem( "http://sto.f2o.org/crux/wiki/",
         "CRUX Linux Wiki page", "Stoyan Zhekov" );
docItem( "http://projectdream.org/publications/sw/uml.html",
         "Installing CRUX into a UML", "Lukas Beeler" );
?>
</ul>
