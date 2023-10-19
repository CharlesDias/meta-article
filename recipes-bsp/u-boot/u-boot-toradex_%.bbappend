do_configure:append() {
    # Remove existing fdtfile, if there is one
    sed -i '/"fdtfile=.*\\0" \\/d' ${S}/include/configs/colibri-imx6ull.h
    # Add new fdtfile, "my-custom-devicetree-file.dtb" should be replaced with your device tree binary file
    sed -i 's/\("fdt_board=.*\\0" \\\)/\0\n      "fdtfile=my-custom-devicetree-file.dtb\\0" \\/' ${S}/include/configs/colibri-imx6ull.h
}