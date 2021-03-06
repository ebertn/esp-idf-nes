#
# Component Makefile
#

COMPONENT_SRCDIRS := .

COMPONENT_ADD_INCLUDEDIRS := include

COMPONENT_ADD_LDFLAGS := -lpthread

ifdef CONFIG_ENABLE_STATIC_TASK_CLEAN_UP_HOOK
COMPONENT_ADD_LDFLAGS += -Wl,--wrap=vPortCleanUpTCB
endif
