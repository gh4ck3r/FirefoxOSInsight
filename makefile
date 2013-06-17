TOP				:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
SRCROOT			:= $(TOP)/src
DEPDIR			:= $(TOP)/.deps
XULRUNNER_DIR	:= $(TOP)/xulrunner-sdk
XULRUNNER_IDL	:= $(XULRUNNER_DIR)/idl
XULRUNNER_SDK	:= $(XULRUNNER_DIR)/sdk/bin

TARGET	:= FirefoxOSInsight.xpi

EXCLUDES := makefile
EXCLUDES += *.idl

TYPELIB_COMPILER := $(XULRUNNER_SDK)/typelib.py

ZIP	:= zip

.PHONY: all
all: $(TARGET)

IDLS		:= $(wildcard $(SRCROOT)/components/*.idl)
TYPELIBS	:= $(IDLS:%.idl=%.xpt)

$(TARGET): $(TYPELIBS)
	@echo "Publish $(@F)"
	@cd $(SRCROOT) && $(ZIP) -qr ../$@ * -x $(EXCLUDES) && cd ..

.PHONY: clean
clean:
	@rm -rf $(TARGET)
	@rm -rf $(TYPELIBS)
	@rm -rf $(DEPDIR)

vpath %.idl $(SRCROOT)/components
%.xpt: %.idl
	@echo "Compile $(<F)"
	@mkdir -p $(DEPDIR)
	@$(TYPELIB_COMPILER) -I $(XULRUNNER_IDL) -d $(DEPDIR)/$(@F:%.xpt=%.d) -o $@ $<

-include $(DEPDIR)/*.d
