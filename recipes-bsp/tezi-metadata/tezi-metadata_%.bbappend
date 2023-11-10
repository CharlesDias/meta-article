FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

# Modify the variables below to select right files.
MKT = "marketing_article.tar"
ICON = "toradexlinux_article.png"

SRC_URI:append = " \
    file://${MKT};unpack=false \
	file://${ICON} \
"

do_deploy:append(){
    rm ${DEPLOYDIR}/marketing.tar
    install -m 644 ${WORKDIR}/${MKT} ${DEPLOYDIR}/marketing.tar

    rm ${DEPLOYDIR}/toradexlinux.png
    install -m 644 ${WORKDIR}/${ICON} ${DEPLOYDIR}/toradexlinux.png
}