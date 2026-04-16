set shell := ["bash", "-euo", "pipefail", "-c"]

default: compile

compile jobs="5":
    qmk userspace-compile -j {{jobs}}

flash-voyager:
    dfu-util -d 3297:0791 -a 0 -s 0x08002000:leave -D zsa_voyager_graphene.bin

copy-uf2 file:
    if [[ ! -f "{{file}}" ]]; then echo "Missing firmware: {{file}}"; exit 1; fi
    while ! cp "{{file}}" /Volumes/RPI-RP2; do sleep 1; done

flash-halcyon-display:
    just copy-uf2 splitkb_halcyon_corne_rev2_graphene_display.uf2

flash-halcyon-trackpad:
    just copy-uf2 splitkb_halcyon_corne_rev2_graphene_cirque_trackpad.uf2
