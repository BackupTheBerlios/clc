PROCARGS=--stringparam section.autolabel 1 --stringparam shade.verbatim 1 \
	 --stringparam toc.section.depth 1

PDF_PROCARGS=--stringparam paper.type A4 --stringparam fop.extensions 1 \
	     --stringparam body.font.family sans-serif \

FO_SHEET=dbjw-fo.xsl

all:	html fo

clean:
	-rm -rf *.aux *.log *.pdf *.fo *.html *.out

html:
	-xsltproc ${PROCARGS} \
		  --xinclude \
		  ~/src/cvs/prt-get_db/dbjw-html.xsl \
		  clc-cvs.xml > clc-cvs.html
fo-ref:	
	-xsltproc ${PROCARGS} ${PDF_PROCARGS} \
	          --xinclude \
		  ~/src/cvs/prt-get_db/dbjw-fo-refcard.xsl \
		  clc-cvs.xml > clc-cvs.fo

fo:	
	-xsltproc ${PROCARGS} ${PDF_PROCARGS} \
	          --xinclude \
		  ~/src/cvs/prt-get_db/dbjw-fo.xsl \
		  clc-cvs.xml > clc-cvs.fo


ps:
	-fop.sh clc-cvs.fo -ps clc-cvs.ps
pdf:
	-fop.sh clc-cvs.fo -pdf clc-cvs.pdf

pdf2:
	-fop.sh clc-cvs.fo -ps clc-cvs.ps
	-psnup -pA4 -2 clc-cvs.ps clc-cvs-2.ps
	-ps2pdf -sPAPERSIZE=a4 clc-cvs-2.ps
