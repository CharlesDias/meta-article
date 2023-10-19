# It adds additional configuration options to the kernel build process
#
# Copyright (C) 2023 Charles Dias
#
# SPDX-License-Identifier: MIT

FILESEXTRAPATHS:prepend := "${THISDIR}/linux-toradex:"

CUSTOM_DEVICETREE = "my-custom-devicetree-file.dts"

SRC_URI += " \ 
    file://${CUSTOM_DEVICETREE} \
    "

do_configure:append() {
    cp ${WORKDIR}/${CUSTOM_DEVICETREE} ${S}/arch/arm/boot/dts
}