LIBCOCOBOT_VERSION = 0.1
LIBCOCOBOT_URL = https://github.com/cocobot/libcocobot/archive/$(LIBCOCOBOT_VERSION).tar.gz
LIBCOCOBOT_ARCHIVE = libcocobot-$(LIBCOCOBOT_VERSION).tar.gz
LIBCOCOBOT_GIT_UPSTREAM_URL = git@github.com:cocobot/libcocobot.git

# File path
ifeq ($(CONFIG_LIBCOCOBOT_USE_GIT),y)
LIBCOCOBOT_FILE_PATH=git
else
LIBCOCOBOT_FILE_PATH=mcual-$(LIBCOCOBOT_VERSION)
endif

# Include files
LIBCOCOBOT_INCLUDE_PATH=$(LIBCOCOBOT_FILE_PATH)/include/

LIBCOCOBOT_SRC_FILES= $(LIBCOCOBOT_FILE_PATH)/src/console/console.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/lcd/lcd.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/trajectory/trajectory.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/position/position.c
LIBCOCOBOT_SRC_FILES+=$(LIBCOCOBOT_FILE_PATH)/src/asserv/asserv.c

GLOBAL_LDFLAGS+=-lm

$(eval $(call pkg-generic,LIBCOCOBOT))
