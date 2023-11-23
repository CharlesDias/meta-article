IMAGE_CLASSES:append = " image_type_tezi"
IMAGE_FSTYPES:append = " teziimg"
TORADEX_PRODUCT_IDS = "0036 0040 0044 0045"
TORADEX_PRODUCT_IDS[0036] = "my-custom-devicetree-file.dtb"
TORADEX_PRODUCT_IDS[0040] = "my-custom-devicetree-file.dtb"
TORADEX_PRODUCT_IDS[0044] = "my-custom-devicetree-file.dtb"
TORADEX_PRODUCT_IDS[0045] = "my-custom-devicetree-file.dtb"

TORADEX_FLASH_TYPE = "rawnand"

WIC_CREATE_EXTRA_ARGS:append = " --no-fstab-update"

MACHINE_NAME = "Colibri-iMX6ULL"

MACHINE_EXTRA_RRECOMMENDS:append = " mwifiexconf"

KERNEL_DEVICETREE:append = " \
    imx6ull-colibri-aster.dtb \
    imx6ull-colibri-iris.dtb \
    imx6ull-colibri-iris-v2.dtb \
    imx6ull-colibri-wifi-aster.dtb \
    imx6ull-colibri-wifi-iris.dtb \
    imx6ull-colibri-wifi-iris-v2.dtb \
"

PREFERRED_PROVIDER_virtual/kernel = "linux-toradex"
PREFERRED_PROVIDER_virtual/kernel:preempt-rt = "linux-toradex"
PREFERRED_PROVIDER_virtual/kernel:use-mainline-bsp = "linux-toradex-mainline"
PREFERRED_PROVIDER_virtual/kernel:use-mainline-bsp:preempt-rt = "linux-toradex-mainline-rt"
PREFERRED_PROVIDER_virtual/dtb:use-mainline-bsp = "device-tree-overlays-mainline"

IMX_DEFAULT_BOOTLOADER:colibri-imx6ull = "u-boot-toradex"
PREFERRED_PROVIDER_u-boot-default-script = "u-boot-distro-boot"

MACHINE_FIRMWARE:remove:use-mainline-bsp = "firmware-imx-vpu-imx6q firmware-imx-vpu-imx6d"

UBOOT_DTB_LOADADDRESS:colibri-imx6ull = "0x88200000"
UBOOT_DTBO_LOADADDRESS:colibri-imx6ull = "0x88300000"
UBOOT_ENTRYPOINT:colibri-imx6ull = "0x84200000"
UBOOT_MAKE_TARGET:colibri-imx6ull = "u-boot.imx"
UBOOT_RD_LOADADDRESS:colibri-imx6ull = "0x8A400000"
