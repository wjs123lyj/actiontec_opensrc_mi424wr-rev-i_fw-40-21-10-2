/*
  $Id: fore200e_mkfirm.c,v 1.1.1.1 2007/05/07 23:29:19 jungo Exp $

  mkfirm.c: generates a C readable file from a binary firmware image

  Christophe Lizzi (lizzi@{csti.fr, cnam.fr}), June 1999.
  
  This software may be used and distributed according to the terms
  of the GNU General Public License, incorporated herein by reference.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

char* default_basename = "pca200e"; /* was initially written for the PCA-200E firmware */
char* default_infname  = "<stdin>";
char* default_outfname = "<stdout>";

char* progname;
int   verbose  = 0;
int   inkernel = 0;


void usage(void)
{
    fprintf(stderr,
	    "%s: [-v] [-k] [-b basename ] [-i firmware.bin] [-o firmware.c]\n",
	    progname);
    exit(-1);
}


int main(int argc, char** argv)
{
    time_t   now;
    char*    infname  = NULL;
    char*    outfname = NULL;
    char*    basename = NULL;
    FILE*    infile;
    FILE*    outfile;
    unsigned firmsize;
    int      c;

    progname = *(argv++);
    
    while (argc > 1) {
        if ((*argv)[0] == '-') {
            switch ((*argv)[1]) {
	    case 'i':
		if (argc-- < 3)
		    usage();
		infname = *(++argv);
		break;
	    case 'o':
		if (argc-- < 3)
		    usage();
		outfname = *(++argv);
		break;
	    case 'b':
		if (argc-- < 3)
		    usage();
		basename = *(++argv);
		break;
	    case 'v':
		verbose = 1;
		break;
	    case 'k':
		inkernel = 1;
		break;
	    default:
		usage();
            }
	}
	else {
	    usage();
	}
	argc--;
        argv++;
    }
    
    if (infname != NULL) {
	infile = fopen(infname, "r");
	if (infile == NULL) {
	    fprintf(stderr, "%s: can't open %s for reading\n",
		    progname, infname);
	    exit(-2);
	}
    }
    else {
	infile = stdin;
	infname = default_infname;
    }

    if (outfname) {
	outfile = fopen(outfname, "w");
	if (outfile == NULL) {
	    fprintf(stderr, "%s: can't open %s for writing\n",
		    progname, outfname);
	    exit(-3);
	}
    }
    else {
	outfile = stdout;
	outfname = default_outfname;
    }

    if (basename == NULL)
	basename = default_basename;

    if (verbose) {
	fprintf(stderr, "%s: input file = %s\n", progname, infname );
	fprintf(stderr, "%s: output file = %s\n", progname, outfname );
	fprintf(stderr, "%s: firmware basename = %s\n", progname, basename );
    }

    time(&now);
    fprintf(outfile, "/*\n  generated by %s from %s on %s"
	    "  DO NOT EDIT!\n*/\n\n",
	    progname, infname, ctime(&now));

    if (inkernel)
	fprintf(outfile, "#include <linux/init.h>\n\n" );
    
    /* XXX force 32 bit alignment? */
    fprintf(outfile, "const unsigned char%s %s_data[] = {\n", 
	    inkernel ? " __initdata" : "", basename );
    
    c = getc(infile);
    fprintf(outfile,"\t0x%02x", c);
    firmsize = 1;
    
    while ((c = getc(infile)) >= 0) {
	
	if (firmsize++ % 8)
	    fprintf(outfile,", 0x%02x", c);
	else
	    fprintf(outfile,",\n\t0x%02x", c);
    }

    fprintf(outfile, "\n};\n\n");

    fprintf(outfile, "const unsigned int%s %s_size = %u;\n",
	    inkernel ? " __initdata" : "", basename, firmsize );

    if (infile != stdin)
	fclose(infile);
    if (outfile != stdout)
	fclose(outfile);

    if(verbose)
	fprintf(stderr, "%s: firmware size = %u\n", progname, firmsize);

    exit(0);
}
