VERSION = 0.1.0

GIT_VERSION = $$system(git --git-dir $$PWD/.git --work-tree $$PWD describe --always --tags)

!contains(GIT_VERSION,\d+\.\d+\.\d+) {
    isEmpty(GIT_VERSION) {
        GIT_VERSION = $$VERSION
    } else { # otherwise construct proper git describe string
        GIT_COMMIT_COUNT = $$system($$BASE_GIT_COMMAND rev-list HEAD --count 2> $$NULL_DEVICE)
        isEmpty(GIT_COMMIT_COUNT) {
            GIT_COMMIT_COUNT = 0
        }
        GIT_VERSION = $$VERSION-$$GIT_COMMIT_COUNT-g$$GIT_VERSION
    }
}

DEFINES += GIT_VERSION=\\\"$$GIT_VERSION\\\"

macx {
    INFO_PLIST_PATH = $$shell_quote($${OUT_PWD}/$${TARGET}.app/Contents/Info.plist)
    QMAKE_POST_LINK += /usr/libexec/PlistBuddy -c \"Set :CFBundleShortVersionString $${VERSION}\" $${INFO_PLIST_PATH}
}
