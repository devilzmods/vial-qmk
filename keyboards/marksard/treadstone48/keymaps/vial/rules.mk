#MOUSEKEY_ENABLE = yes       # Mouse keys

RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
#OLED_ENABLE = yes
#OLED_DRIVER = SSD1306
#LTO_ENABLE = yes

VIA_ENABLE = yes
VIAL_ENABLE = yes

#Firmware size reduction for vial
LTO_ENABLE = yes
TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = no
COMBO_ENABLE = yes
OLED_ENABLE = no
MOUSEKEY_ENABLE = no

# If you want to change the display of OLED, you need to change here
SRC +=  ./common/oled_helper.c \
