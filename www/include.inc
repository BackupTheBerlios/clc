<?

class LinkPrinter
{
    function printLink( $name, $desc ) {
        if ( $name == $this->pageName ) {
            print "<b>$desc</b>";
        } else {
            print "<a href=\"";
            print $this->page . $name;
            print "\">$desc</a>";
        }
    }
    function setPage( $page ) { $this->page = $page; }
    function setPageName( $pageName ) { $this->pageName = $pageName; }
};

?>