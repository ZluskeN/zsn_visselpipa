# zsn_visselpipa

This mod adds an Acme Thunderer whistle item, which can be used through ACE 3 self interaction. It can be heard at a range of 1600 meters,
in accordance with the original specs from 1884. It can be found in the virtual arsenal under misc items. The classname is 'ZSN_Whistle'

## Build locally

Make sure pboproject and any dependencies are installed from https://armaservices.maverick-applications.com/Products/MikerosDosTools/FileBrowserFree

Double click build.bat to generate pbo files in @zsn_visselpipa.
Check zsn_visselpipa/temp for build logs.

## Build on Jenkins

Project uses Jenkinsfile to define build steps.
Add the repository or organization to Jenkins as a pipeline job and it should pick it up automatically.

It requires a node with the label "mikero" and pboproject must be available in PATH
