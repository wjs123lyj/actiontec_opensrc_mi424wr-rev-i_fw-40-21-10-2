include ../global.def

TARGET = dbus-daemon 
#dbus-daemon-launch-helper dbus-daemon-launch-helper-test

#	activation.h	\
#	activation-exit-codes.h			\
#	activation-helper.h	\
#	bus.h					\
#	config-parser.h				\
#	config-parser-common.h			\
#	config-parser-trivial.h	\
#	connection.h				\
#	desktop-file.h				\
#	dir-watch.h				\
#	dispatch.h				\
#	driver.h				\
#	expirelist.h				\
#	policy.h				\
#	selinux.h				\
#	services.h				\
#	signals.h				\
#	test.h					\
#	utils.h

OBJS_dbus-daemon = activation.o \
										 bus.o \
										 config-parser.o \
										 config-parser-common.o \
										 config-parser-common.o \
										 connection.o \
										 desktop-file.o \
										 dir-watch-inotify.o \
										 dispatch.o \
										 driver.o \
										 expirelist.o \
										 policy.o \
										 selinux.o \
										 services.o \
										 signals.o \
										 test.o \
										 utils.o \
										 config-loader-expat.o \
										 main.o 

OBJS_dbus-daemon-launch-helper = config-loader-expat.o \
										 config-parser-common.o \
										 config-parser-trivial.o \
										 desktop-file.o \
										 utils.o \
										 activation-helper.o \
										 activation-helper-bin.o
										 
OBJS_dbus-daemon-launch-helper-test = activation-helper-bin.o	\
										 config-loader-expat.o \
										 config-parser-common.o \
										 config-parser-trivial.o \
										 desktop-file.o \
										 utils.o \
										 activation-helper.o

CFLAGS += -Wall -I./ -I../ -I../../expat -DDBUS_COMPILATION -DDBUS_SYSTEM_CONFIG_FILE=\""/etc/dbus/system.conf"\"	
LDFLAGS += -L../dbus -ldbus -L../../expat -lexpat -lpthread

all: $(TARGET)


all: $(TARGET)

ifeq ($(TARGET_PLATFORM),BHR2)
$(TARGET): $(OBJS_dbus-daemon)
	$(RCC) -o $@ $^ $(LDFLAGS)        
.c.o:
	$(RCC) -c -o $@ $(CFLAGS) $(IFLAGS) $<

else
$(TARGET): $(OBJS_dbus-daemon)
	$(CC) -o $@ $^ $(LDFLAGS)
endif

clean:
	rm $(TARGET) *.o 

#include $(BUILD_DIR)/make.deprules

#-include $(OBJS:.o=.d)
