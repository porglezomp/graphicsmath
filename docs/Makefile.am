pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = @libfilename@.pc

if HAVE_DOXYGEN
#directory = $(top_srcdir)/docs/man

dist_man_MANS = #none right now

doxyfile.stamp:
	$(DOXYGEN) Doxyfile
	echo Timestamp > doxyfile.stamp

CLEANFILES = doxyfile.stamp

all-local: doxyfile.stamp
#clean-local:
#	rm -rf $(top_srcdir)/docs/man
   
endif
