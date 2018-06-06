DEPENDS += "${@bb.utils.contains('DISTRO_FEATURES', 'x11 opengl', 'libpng libglu glfw gtk+3', '', d)}"

EXTRA_OECMAKE = " \
	-DBUILD_SHARED_LIBS:BOOL=ON -DBUILD_UNIT_TESTS:BOOL=OFF -DBUILD_EXAMPLES:BOOL=ON -DUSE_SYSTEM_LIBUSB:BOOL=ON \
	-DBUILD_GRAPHICAL_EXAMPLES:BOOL=${@bb.utils.contains('DISTRO_FEATURES', 'x11 opengl', 'ON', 'OFF', d)} \
"

PACKAGECONFIG ??= ""

PACKAGES += "\
	${PN}-examples \
	${PN}-tools \
	${PN}-debug-tools \
"

PACKAGES += "${@bb.utils.contains('DISTRO_FEATURES', 'x11 opengl', '${PN}-graphical-examples', '', d)}"

FILES_${PN}-examples = "\
	${bindir}/rs-color \
	${bindir}/rs-depth \
	${bindir}/rs-distance \
	${bindir}/rs-save-to-disk \
"

FILES_${PN}-graphical-examples = "\
	${bindir}/rs-align \
	${bindir}/rs-capture \
	${bindir}/rs-measure \
	${bindir}/rs-multicam \
	${bindir}/rs-pointcloud \
	${bindir}/rs-post-processing \
	${bindir}/rs-record-playback \
	${bindir}/rs-sensor-control \
	${bindir}/rs-software-device \
"

FILES_${PN}-tools = "\
    ${bindir}/realsense-viewer \
	${bindir}/rs-convert \
    ${bindir}/rs-depth-quality \
"

FILES_${PN}-debug-tools = "\
    ${bindir}/rs-data-collect \
    ${bindir}/rs-enumerate-devices \
    ${bindir}/rs-fw-logger \
    ${bindir}/rs-rosbag-inspector \
    ${bindir}/rs-terminal \
"