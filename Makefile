#############################################################################
# Makefile for building: Bio_Interface
# Generated by qmake (2.01a) (Qt 4.7.3) on: jeu. 23. juin 02:10:59 2011
# Project:  Bio_Interface.pro
# Template: app
# Command: c:\qtsdk\symbian\sdks\symbian3qt473\bin\qmake.exe -spec ..\..\..\..\QtSDK\Symbian\SDKs\Symbian3Qt473\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc -o bld.inf Bio_Interface.pro
#############################################################################

MAKEFILE          = Makefile
QMAKE             = c:\qtsdk\symbian\sdks\symbian3qt473\bin\qmake.exe
DEL_FILE          = del 2> NUL
DEL_DIR           = rmdir
CHK_DIR_EXISTS    = if not exist
MKDIR             = mkdir
MOVE              = move
DEBUG_PLATFORMS   = winscw gcce armv5 armv6
RELEASE_PLATFORMS = gcce armv5 armv6
MAKE              = make
SBS               = sbs

DEFINES	 = -DSYMBIAN -DUNICODE -DQT_KEYPAD_NAVIGATION -DQT_SOFTKEYS_ENABLED -DQT_USE_MATH_H_FLOATS -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH	 =  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/include/QtCore"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/include/QtGui"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/include"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/mkspecs/common/symbian"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/stdapis"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/stdapis/sys"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/stdapis/stlportv5"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/mw"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/platform/mw"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/platform"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/platform/loc"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/platform/mw/loc"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/platform/loc/sc"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/include/platform/mw/loc/sc"  -I"C:/Users/Dadomba/Code/Bio_Interface/moc"  -I"C:/Users/Dadomba/Code/Bio_Interface/ui"  -I"C:/Users/Dadomba/Code/Bio_Interface" 
first: default

all: debug release

default: debug-winscw
qmake:
	$(QMAKE) "C:/Users/Dadomba/Code/Bio_Interface/Bio_Interface.pro"  -spec ..\..\..\..\QtSDK\Symbian\SDKs\Symbian3Qt473\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc

bld.inf: C:/Users/Dadomba/Code/Bio_Interface/Bio_Interface.pro
	$(QMAKE) "C:/Users/Dadomba/Code/Bio_Interface/Bio_Interface.pro"  -spec ..\..\..\..\QtSDK\Symbian\SDKs\Symbian3Qt473\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc

c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc: 
	$(QMAKE) "C:/Users/Dadomba/Code/Bio_Interface/Bio_Interface.pro"  -spec ..\..\..\..\QtSDK\Symbian\SDKs\Symbian3Qt473\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc

debug: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1
clean-debug: bld.inf
	$(SBS) reallyclean --toolcheck=off -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1
freeze-debug: bld.inf
	$(SBS) freeze -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1
release: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1
clean-release: bld.inf
	$(SBS) reallyclean --toolcheck=off -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1
freeze-release: bld.inf
	$(SBS) freeze -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1

debug-winscw: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c winscw_udeb.mwccinc
clean-debug-winscw: bld.inf
	$(SBS) reallyclean -c winscw_udeb.mwccinc
freeze-debug-winscw: bld.inf
	$(SBS) freeze -c winscw_udeb.mwccinc
debug-gcce: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c arm.v5.udeb.gcce4_4_1
clean-debug-gcce: bld.inf
	$(SBS) reallyclean -c arm.v5.udeb.gcce4_4_1
freeze-debug-gcce: bld.inf
	$(SBS) freeze -c arm.v5.udeb.gcce4_4_1
debug-armv5: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c armv5_udeb
clean-debug-armv5: bld.inf
	$(SBS) reallyclean -c armv5_udeb
freeze-debug-armv5: bld.inf
	$(SBS) freeze -c armv5_udeb
debug-armv6: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c armv6_udeb
clean-debug-armv6: bld.inf
	$(SBS) reallyclean -c armv6_udeb
freeze-debug-armv6: bld.inf
	$(SBS) freeze -c armv6_udeb
release-gcce: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c arm.v5.urel.gcce4_4_1
clean-release-gcce: bld.inf
	$(SBS) reallyclean -c arm.v5.urel.gcce4_4_1
freeze-release-gcce: bld.inf
	$(SBS) freeze -c arm.v5.urel.gcce4_4_1
release-armv5: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c armv5_urel
clean-release-armv5: bld.inf
	$(SBS) reallyclean -c armv5_urel
freeze-release-armv5: bld.inf
	$(SBS) freeze -c armv5_urel
release-armv6: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c armv6_urel
clean-release-armv6: bld.inf
	$(SBS) reallyclean -c armv6_urel
freeze-release-armv6: bld.inf
	$(SBS) freeze -c armv6_urel
debug-armv5-gcce4.4.1: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c arm.v5.udeb.gcce4_4_1
clean-debug-armv5-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v5.udeb.gcce4_4_1
freeze-debug-armv5-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v5.udeb.gcce4_4_1
release-armv5-gcce4.4.1: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c arm.v5.urel.gcce4_4_1
clean-release-armv5-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v5.urel.gcce4_4_1
freeze-release-armv5-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v5.urel.gcce4_4_1
debug-armv6-gcce4.4.1: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c arm.v6.udeb.gcce4_4_1
clean-debug-armv6-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v6.udeb.gcce4_4_1
freeze-debug-armv6-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v6.udeb.gcce4_4_1
release-armv6-gcce4.4.1: c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc bld.inf
	$(SBS) -c arm.v6.urel.gcce4_4_1
clean-release-armv6-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v6.urel.gcce4_4_1
freeze-release-armv6-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v6.urel.gcce4_4_1

export: bld.inf
	$(SBS) export -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1 -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1

cleanexport: bld.inf
	$(SBS) cleanexport -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1 -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1

freeze: freeze-release

check: first

run:
	call C:/QtSDK/Symbian/SDKs/Symbian3Qt473/epoc32/release/winscw/udeb/Bio_Interface.exe $(QT_RUN_OPTIONS)

runonphone: sis
	runonphone $(QT_RUN_ON_PHONE_OPTIONS) --sis Bio_Interface.sis Bio_Interface.exe $(QT_RUN_OPTIONS)

Bio_Interface_template.pkg: C:/Users/Dadomba/Code/Bio_Interface/Bio_Interface.pro
	$(MAKE) -f $(MAKEFILE) qmake

Bio_Interface_installer.pkg: C:/Users/Dadomba/Code/Bio_Interface/Bio_Interface.pro
	$(MAKE) -f $(MAKEFILE) qmake

Bio_Interface_stub.pkg: C:/Users/Dadomba/Code/Bio_Interface/Bio_Interface.pro
	$(MAKE) -f $(MAKEFILE) qmake

sis: Bio_Interface_template.pkg
	$(if $(wildcard .make.cache), $(MAKE) -f $(MAKEFILE) ok_sis MAKEFILES=.make.cache , $(if $(QT_SIS_TARGET), $(MAKE) -f $(MAKEFILE) ok_sis , $(MAKE) -f $(MAKEFILE) fail_sis_nocache ) )

ok_sis:
	createpackage -g $(QT_SIS_OPTIONS) Bio_Interface_template.pkg $(QT_SIS_TARGET) $(QT_SIS_CERTIFICATE) $(QT_SIS_KEY) $(QT_SIS_PASSPHRASE)

unsigned_sis: Bio_Interface_template.pkg
	$(if $(wildcard .make.cache), $(MAKE) -f $(MAKEFILE) ok_unsigned_sis MAKEFILES=.make.cache , $(if $(QT_SIS_TARGET), $(MAKE) -f $(MAKEFILE) ok_unsigned_sis , $(MAKE) -f $(MAKEFILE) fail_sis_nocache ) )

ok_unsigned_sis:
	createpackage -g $(QT_SIS_OPTIONS) -o Bio_Interface_template.pkg $(QT_SIS_TARGET)

Bio_Interface.sis:
	$(MAKE) -f $(MAKEFILE) sis

installer_sis: Bio_Interface_installer.pkg sis
	$(MAKE) -f $(MAKEFILE) ok_installer_sis

ok_installer_sis: Bio_Interface_installer.pkg
	createpackage $(QT_SIS_OPTIONS) Bio_Interface_installer.pkg - $(QT_SIS_CERTIFICATE) $(QT_SIS_KEY) $(QT_SIS_PASSPHRASE)

unsigned_installer_sis: Bio_Interface_installer.pkg unsigned_sis
	$(MAKE) -f $(MAKEFILE) ok_unsigned_installer_sis

ok_unsigned_installer_sis: Bio_Interface_installer.pkg
	createpackage $(QT_SIS_OPTIONS) -o Bio_Interface_installer.pkg

fail_sis_nocache:
	$(error Project has to be built or QT_SIS_TARGET environment variable has to be set before calling 'SIS' target)

stub_sis: Bio_Interface_stub.pkg
	$(if $(wildcard .make.cache), $(MAKE) -f $(MAKEFILE) ok_stub_sis MAKEFILES=.make.cache , $(if $(QT_SIS_TARGET), $(MAKE) -f $(MAKEFILE) ok_stub_sis , $(MAKE) -f $(MAKEFILE) fail_sis_nocache ) )

ok_stub_sis:
	createpackage -s $(QT_SIS_OPTIONS) Bio_Interface_stub.pkg $(QT_SIS_TARGET) $(QT_SIS_CERTIFICATE) $(QT_SIS_KEY) $(QT_SIS_PASSPHRASE)

deploy: sis
	call Bio_Interface.sis

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc\moc_mainwindow.cpp moc\moc_addspeciesdialog.cpp moc\moc_manager.cpp moc\moc_inhdialog.cpp moc\moc_complexdialog.cpp moc\moc_synthdialog.cpp moc\moc_systemdialog.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc\moc_mainwindow.cpp moc\moc_addspeciesdialog.cpp moc\moc_manager.cpp moc\moc_inhdialog.cpp moc\moc_complexdialog.cpp moc\moc_synthdialog.cpp moc\moc_systemdialog.cpp
moc\moc_mainwindow.cpp: bio_cst.h \
		reaction.h \
		Species.h \
		addspeciesdialog.h \
		inhdialog.h \
		complexdialog.h \
		synthdialog.h \
		systemdialog.h \
		mainwindow.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Users\Dadomba\Code\Bio_Interface\mainwindow.h -o c:\Users\Dadomba\Code\Bio_Interface\moc\moc_mainwindow.cpp

moc\moc_addspeciesdialog.cpp: addspeciesdialog.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Users\Dadomba\Code\Bio_Interface\addspeciesdialog.h -o c:\Users\Dadomba\Code\Bio_Interface\moc\moc_addspeciesdialog.cpp

moc\moc_manager.cpp: mainwindow.h \
		bio_cst.h \
		reaction.h \
		Species.h \
		addspeciesdialog.h \
		inhdialog.h \
		complexdialog.h \
		synthdialog.h \
		systemdialog.h \
		species.h \
		inh.h \
		Reaction.h \
		complex.h \
		synth.h \
		system.h \
		manager.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Users\Dadomba\Code\Bio_Interface\manager.h -o c:\Users\Dadomba\Code\Bio_Interface\moc\moc_manager.cpp

moc\moc_inhdialog.cpp: inhdialog.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Users\Dadomba\Code\Bio_Interface\inhdialog.h -o c:\Users\Dadomba\Code\Bio_Interface\moc\moc_inhdialog.cpp

moc\moc_complexdialog.cpp: complexdialog.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Users\Dadomba\Code\Bio_Interface\complexdialog.h -o c:\Users\Dadomba\Code\Bio_Interface\moc\moc_complexdialog.cpp

moc\moc_synthdialog.cpp: synthdialog.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Users\Dadomba\Code\Bio_Interface\synthdialog.h -o c:\Users\Dadomba\Code\Bio_Interface\moc\moc_synthdialog.cpp

moc\moc_systemdialog.cpp: systemdialog.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Users\Dadomba\Code\Bio_Interface\systemdialog.h -o c:\Users\Dadomba\Code\Bio_Interface\moc\moc_systemdialog.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: ui\qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) ui\qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui\ui_mainwindow.h ui\ui_addspeciesdialog.h ui\ui_inhdialog.h ui\ui_complexdialog.h ui\ui_synthdialog.h ui\ui_systemdialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui\ui_mainwindow.h ui\ui_addspeciesdialog.h ui\ui_inhdialog.h ui\ui_complexdialog.h ui\ui_synthdialog.h ui\ui_systemdialog.h
ui\ui_mainwindow.h: mainwindow.ui
	c:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\uic.exe c:\Users\Dadomba\Code\Bio_Interface\mainwindow.ui -o c:\Users\Dadomba\Code\Bio_Interface\ui\ui_mainwindow.h

ui\ui_addspeciesdialog.h: addspeciesdialog.ui
	c:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\uic.exe c:\Users\Dadomba\Code\Bio_Interface\addspeciesdialog.ui -o c:\Users\Dadomba\Code\Bio_Interface\ui\ui_addspeciesdialog.h

ui\ui_inhdialog.h: inhdialog.ui
	c:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\uic.exe c:\Users\Dadomba\Code\Bio_Interface\inhdialog.ui -o c:\Users\Dadomba\Code\Bio_Interface\ui\ui_inhdialog.h

ui\ui_complexdialog.h: complexdialog.ui
	c:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\uic.exe c:\Users\Dadomba\Code\Bio_Interface\complexdialog.ui -o c:\Users\Dadomba\Code\Bio_Interface\ui\ui_complexdialog.h

ui\ui_synthdialog.h: synthdialog.ui
	c:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\uic.exe c:\Users\Dadomba\Code\Bio_Interface\synthdialog.ui -o c:\Users\Dadomba\Code\Bio_Interface\ui\ui_synthdialog.h

ui\ui_systemdialog.h: systemdialog.ui
	c:\QtSDK\Symbian\SDKs\Symbian3Qt473\bin\uic.exe c:\Users\Dadomba\Code\Bio_Interface\systemdialog.ui -o c:\Users\Dadomba\Code\Bio_Interface\ui\ui_systemdialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

dodistclean:
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_template.pkg" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_template.pkg"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_stub.pkg" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_stub.pkg"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_installer.pkg" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_installer.pkg"
	-@ if EXIST "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\distribution.policy.s60" $(DEL_FILE)  "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\distribution.policy.s60"
	-@ if EXIST "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_emulator_deployment.flm" $(DEL_FILE)  "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_emulator_deployment.flm"
	-@ if EXIST "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_extra_pre_targetdep.flm" $(DEL_FILE)  "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_extra_pre_targetdep.flm"
	-@ if EXIST "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_post_link.flm" $(DEL_FILE)  "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_post_link.flm"
	-@ if EXIST "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_store_build.flm" $(DEL_FILE)  "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qmake_store_build.flm"
	-@ if EXIST "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qt.xml" $(DEL_FILE)  "c:\QtSDK\Symbian\SDKs\Symbian3Qt473\epoc32\tools\makefile_templates\qt\qt.xml"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Makefile" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Makefile"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_exe.mmp" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_exe.mmp"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_reg.rss" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface_reg.rss"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.rss" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.rss"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\Bio_Interface.loc"
	-@ if EXIST "c:\Users\Dadomba\Code\Bio_Interface\bld.inf" $(DEL_FILE)  "c:\Users\Dadomba\Code\Bio_Interface\bld.inf"

distclean: clean dodistclean

clean: bld.inf
	-$(SBS) reallyclean --toolcheck=off -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1 -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1

