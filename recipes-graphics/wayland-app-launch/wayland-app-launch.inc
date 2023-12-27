SUMMARY = "Wayland application autostart"
DESCRIPTION = "This will start a wayland application after the wayland socket has been created."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

inherit allarch systemd

RDEPENDS:${PN} += "weston-init ${INITIAL_APP_PKGS}"

S = "${WORKDIR}"

SRC_URI = " \
    file://wayland-app-launch.service.in \
"
FILESEXTRAPATHS:prepend := "${THISDIR}/wayland-app-launch:"

APPLICATION_ENVIRONMENT ??= ""

do_compile () {
    sed -e "s:@@wayland-application@@:${WAYLAND_APPLICATION}:" \
        -e "s:@@application-environment@@:${APPLICATION_ENVIRONMENT}:" \
	wayland-app-launch.service.in > wayland-app-launch.service
}

do_install () {
    install -d ${D}${systemd_unitdir}/system/
    install -m 0644 ${WORKDIR}/wayland-app-launch.service ${D}${systemd_unitdir}/system
}

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE:${PN} = "wayland-app-launch.service"
