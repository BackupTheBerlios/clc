<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<!-- clc - cptn loves claudia -->
<html>
<?

include( "include.inc" );

$pageName = "index";
$pageFound = false;
$title = "Home";

// TODO: take out page selection
if ( !isset($p) || $p == "home" ) {
    $pageName = "home";
    $pageFound = true;
    $title = "Home";
} else if ( $p == "search" ) {
    $pageName = "search";
    $pageFound = true;
    $title = "Port Search";
} else if ( $p == "scripts" ) {
    $pageName = "scripts";
    $pageFound = true;
    $title = "Useful Scripts";
} else if ( $p == "about" ) {
    $pageName = "about";
    $pageFound = true;
    $title = "About CLC";
} else if ( $p == "stats" ) {
    $pageName = "stats";
    $pageFound = true;
    $title = "Latests additions and changes";
} else if ( $p == "submit" ) {
    $pageName = "submit";
    $pageFound = true;
    $title = "Submit ports";
} else if ( $p == "links" ) {
    $pageName = "links";
    $pageFound = true;
    $title = "Links";
} else if ( $p == "projects" ) {
    $pageName = "projects";
    $pageFound = true;
    $title = "Projects";
} else if ( $p == "docs" ) {
    $pageName = "docs";
    $pageFound = true;
    $title = "Documents";
}


?>



<head>
<title>
<? print "CLC - " . $title; ?>
</title>
<link href="clc.css" type="text/css" rel="stylesheet"
</head>

<body bgcolor="#ffffff">

<table width="100%" cellspacing="0" cellpadding="5">
<tr bgcolor="#ffffff">
<td>
<h1>CLC - CRUX Linux Community</h1>
</td>
</tr>
</table>


<p>
</p>

<table width="100%" cellpadding="1" cellspacing="0" border="0">
<tr bgcolor="#8888aa">
<td>
<table width="100%" cellpadding="5" cellspacing="0" border="0">
<tr>
<td bgcolor="#f4f4ff">
<!-- NAVIGATION -->
<p>
<?
$lp = new LinkPrinter;
$lp->setPage( "index.php?p=" );
$lp->setPageName( $pageName );


// TODO: take out navigation
$lp->printLink( "home", "Home" );
print "&nbsp;|&nbsp;";
//$lp->printLink( "search", "Search" );
//print "&nbsp;|&nbsp;";
//$lp->printLink( "stats", "Changes & Additions" );
//print "&nbsp;|&nbsp;";
$lp->printLink( "submit", "Submit Ports" );
print "&nbsp;|&nbsp;";
$lp->printLink( "about", "About CLC" );
print "&nbsp;|&nbsp;";
$lp->printLink( "projects", "Projects" );
print "&nbsp;|&nbsp;";
$lp->printLink( "docs", "Documents" );
print "&nbsp;|&nbsp;";
$lp->printLink( "links", "Links" );
?>
</p>
<!-- /NAVIGATION -->
</td>
</tr>
<tr>
<td bgcolor="#ffffff">



<?if ( !$pageFound ) {    ?>
<table><tr bgcolor="#eeeeee"><td>
<small><b>Warning: </b>Invalid page '<? print $p ?>'
                   (Showing index page)</small></td></tr></table>

<? 
}
if ( file_exists( $pageName . ".inc" ) ) {
    include( $pageName . ".inc" );
} else {
    print "<b>Fatal error: Page not found: " . $pageName . ".inc</b><br>";
    print "Please contact <a href=\"mailto:jw@tks6.net\">jw@tks6.net</a>";
    
}
?>

</td>
</tr>
<tr>
<td bgcolor="#f4f4ff">
<small class="footer">Copyright (c) 2003 by the CLC team</small>
</td>
</tr>
</table>

</td>
</tr>
</table>

<!--
<p>
  <a href="http://validator.w3.org/check/referer"><img border="0"
    src="http://www.w3.org/Icons/valid-html401"
    alt="Valid HTML 4.01!" height="31" width="88"></a>
 </p>-->

<p>
<small>Kindly hosted by:</small><br>
<A href="http://developer.berlios.de"> <IMG src="http://developer.berlios.de/bslogo.php?group_id=847" width="124" height="32" border="0" alt="BerliOS Developer Logo"></A>
</p>
</body>
</html>
