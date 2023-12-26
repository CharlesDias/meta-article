# set the following variable to your one and only application which should
# be launched right after weston started

INITIAL_APP_PKGS ?= "qtbase-examples qtwayland"
APPLICATION_ENVIRONMENT ?= 'QT_QPA_PLATFORM=wayland-egl'
WAYLAND_APPLICATION ?= "/opt/DemoProject/bin/DemoProject"

require wayland-app-launch.inc
