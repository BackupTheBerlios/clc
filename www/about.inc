<h3>About CLC</h3>
<p>
We are a group of volunteers providing additional packages and services for
<a href="http://www.crux.nu">CRUX</a> users.
</p>
<p>
Many thanks go to the nice people from the <a href="http://www.lugs.ch/lugs">Linux Users Group Switzerland</a> and especially to <a href="http://www.rubis.ch/~beat">Beat Rubischon</a> for hosting CLC before we moved to berlios.de.</p>
<p>
Thanks also to the Berlios team for providing a nice solution for our project.
</p>

<?
function addAuthor( $name, $nick ) {
    global $i;
    $bgcolor = $i++ % 2 ? "#ffffff" : "#eeeeff";
    print "<tr bgcolor=\"$bgcolor\"><td>$name</td><td>$nick</td></tr>";
}
?>

<h3>People</h3>
<table>
<tr><td><b>Name</b></td><td><b>IRC nick</b></td></tr>

<? 
addAuthor( "Markus Ackermann", "maol" );
addAuthor( "Jürgen Daubert", "jue" );
addAuthor( "Olle Gustafsson", "ogg" );
addAuthor( "Per Lidén", "pli" );
// addAuthor( "Jussi Mäki", "jmki" );
addAuthor( "Matt Housh", "jaeger" );
addAuthor( "Erlend Bergs&aring;s Mikkelsen", "howl" );
addAuthor( "Håvard Moen", "vanilije" );
addAuthor( "Daniel Müller", "danm" );
addAuthor( "Martin Opel", "obbl" );
addAuthor( "Johannes Winkelmann", "cptn" );
?>

</table>

<h3>Other possibilities to contact us</h3>
Most of us can be found on IRC (irc.freenode.net, #crux). We read the CRUX Mailing list, and try to resolve issues reported via <a href="https://developer.berlios.de/bugs/?group_id=847">the berlios bug tracking system</a>.

<h3>Sponsorings</h3>
The following people have contributed to the CLC project by sponsoring us:
<ul>
<li>Rudolf Plaas (<a href="http://www.survearchive.ch">Homepage</a>) has donated a nice HP Notebook to Johannes Winkelmann</li>
</ul>
