<?
function newsItem( $date, $text ) {
    print "<tr><td>$date:</td><td>$text</td></tr>";

}
?>

<!-- NEWSBLOCK -->
<h3>News</h3>
<blockquote>
<table>
<?
newsItem( "14.08.2003", "Database now shows state for CRUX 1.2");
newsItem( "06.08.2003", "Searchable database online again");
// newsItem( "02.07.2003", "Testing starts on berlios...");
// newsItem( "22.05.2003", "Added a sponsoring section on the About CLC page");
// newsItem( "27.04.2003", "Updated GNOME and KDE project pages");
// newsItem( "03.04.2003", "Moving to CRUX 1.1 is nearly complete, all major ports are updated");
// newsItem( "24.03.2003", "We're currently moving updating CLC for CRUX 1.1");
// newsItem( "18.02.2003", "Stats page: new structure, filtering" );
// newsItem( "05.02.2003", "New design online" );
// newsItem( "18.01.2003", "Search database: can search by packager" );
?>
</table>
</blockquote>
<!-- /NEWSBLOCK -->


<p>
CLC is a port collection for the <a href="http://crux.nu">CRUX</a> linux distribution. We also
provide a <a href="?p=search">searchable database</a> of ports in CRUX itself and CLC, plus 
some <a href="?p=docs">documents</a> and <a href="?p=projects">projects</a>.
</p>
<p>
The ports from CLC are provided "as is" without any kind of warranty. 
Use it at your own risk.
</p>

<h3>Quick start</h3>
To get the CLC ports tree, you need to place our 
<a href="files/clc.cvsup">clc.cvsup</a> (if you are using <code>ports</code> version 0.9 or later) or 
<a href="files/supfile.clc">supfile.clc</a> in your 
<code>/etc/ports/</code> directory and
<code>ports -u</code>. After that, you should have the ports in your tree.

<p>
HTTP-only users please have a look at the <a href="projects/httpup/">httpup project page</a>.
</p>

<h3>Maintainers wanted</h3>
We are looking for maintainers for both existing and new ports.
If you'd like to be a part of the CLC
team please have a look at <a href="http://clc.berlios.de/doc/maintainer-guide.html">the maintainer guidelines</a> if you're interested in joining us.

<!--
<h3>Port search</h3>
<form method="get" action="?p=search" >
<p>
You want to know in which port a certain library or binary is?
You want to know more about a port?<br>

<input type="hidden" name="section" value="all">
<input type="hidden" name="p" value="search">

Search CRUX ports for
<input type="radio" checked name="field" value="Name">Ports or
<input type="radio" name="field" value="File">Files containing
<input type="text" name="field_value" value="" >
<input type="Submit" value="search">
<br>
There's an <a href="?p=search">advanced search</a> page with more search options.</p>
</form>
-->

<h3>Report problems/bugs</h3>
We use this <a href="http://crux.fh-regensburg.de/cgi-bin/cvstrac/index">
bug tracking system</a> to keep track of problems.
