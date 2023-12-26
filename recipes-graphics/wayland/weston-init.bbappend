do_install:append() {
    sed -i -e "s/^#\\[shell\\]/[shell]/g" ${D}${sysconfdir}/xdg/weston/weston.ini

    sed -i -e "/panel-position=/d" ${D}${sysconfdir}/xdg/weston/weston.ini
    sed -i -e "/^\[shell\]/a panel-position=none" ${D}${sysconfdir}/xdg/weston/weston.ini
}
