.section .data

.global _ramromDam1SegmentRomStart
_ramromDam1SegmentRomStart:

# VERSION_EU is only one with differences

.ifdef VERSION_EU

.global ramrom_Dam_1
ramrom_Dam_1:
.incbin "assets/ramrom/e/ramrom_Dam_1.bin"
ramrom_Dam_1_end:

.global ramrom_Dam_2
ramrom_Dam_2:
.incbin "assets/ramrom/e/ramrom_Dam_2.bin"
ramrom_Dam_2_end:

.global ramrom_Facility_1
ramrom_Facility_1:
.incbin "assets/ramrom/e/ramrom_Facility_1.bin"
ramrom_Facility_1_end:

.global ramrom_Facility_2
ramrom_Facility_2:
.incbin "assets/ramrom/e/ramrom_Facility_2.bin"
ramrom_Facility_2_end:

.global ramrom_Facility_3
ramrom_Facility_3:
.incbin "assets/ramrom/e/ramrom_Facility_3.bin"
ramrom_Facility_3_end:

.global ramrom_Runway_1
ramrom_Runway_1:
.incbin "assets/ramrom/e/ramrom_Runway_1.bin"
ramrom_Runway_1_end:

.global ramrom_Runway_2
ramrom_Runway_2:
.incbin "assets/ramrom/e/ramrom_Runway_2.bin"
ramrom_Runway_2_end:

.global ramrom_BunkerI_1
ramrom_BunkerI_1:
.incbin "assets/ramrom/e/ramrom_BunkerI_1.bin"
ramrom_BunkerI_1_end:

.global ramrom_BunkerI_2
ramrom_BunkerI_2:
.incbin "assets/ramrom/e/ramrom_BunkerI_2.bin"
ramrom_BunkerI_2_end:

.global ramrom_Silo_1
ramrom_Silo_1:
.incbin "assets/ramrom/e/ramrom_Silo_1.bin"
ramrom_Silo_1_end:

.global ramrom_Silo_2
ramrom_Silo_2:
.incbin "assets/ramrom/e/ramrom_Silo_2.bin"
ramrom_Silo_2_end:

.global ramrom_Frigate_1
ramrom_Frigate_1:
.incbin "assets/ramrom/e/ramrom_Frigate_1.bin"
ramrom_Frigate_1_end:

.global ramrom_Frigate_2
ramrom_Frigate_2:
.incbin "assets/ramrom/e/ramrom_Frigate_2.bin"
ramrom_Frigate_2_end:

.global ramrom_Train
ramrom_Train:
.incbin "assets/ramrom/e/ramrom_Train.bin"
ramrom_Train_end:

.else

.global ramrom_Dam_1
ramrom_Dam_1:
.incbin "assets/ramrom/ramrom_Dam_1.bin"
ramrom_Dam_1_end:

.global ramrom_Dam_2
ramrom_Dam_2:
.incbin "assets/ramrom/ramrom_Dam_2.bin"
ramrom_Dam_2_end:

.global ramrom_Facility_1
ramrom_Facility_1:
.incbin "assets/ramrom/ramrom_Facility_1.bin"
ramrom_Facility_1_end:

.global ramrom_Facility_2
ramrom_Facility_2:
.incbin "assets/ramrom/ramrom_Facility_2.bin"
ramrom_Facility_2_end:

.global ramrom_Facility_3
ramrom_Facility_3:
.incbin "assets/ramrom/ramrom_Facility_3.bin"
ramrom_Facility_3_end:

.global ramrom_Runway_1
ramrom_Runway_1:
.incbin "assets/ramrom/ramrom_Runway_1.bin"
ramrom_Runway_1_end:

.global ramrom_Runway_2
ramrom_Runway_2:
.incbin "assets/ramrom/ramrom_Runway_2.bin"
ramrom_Runway_2_end:

.global ramrom_BunkerI_1
ramrom_BunkerI_1:
.incbin "assets/ramrom/ramrom_BunkerI_1.bin"
ramrom_BunkerI_1_end:

.global ramrom_BunkerI_2
ramrom_BunkerI_2:
.incbin "assets/ramrom/ramrom_BunkerI_2.bin"
ramrom_BunkerI_2_end:

.global ramrom_Silo_1
ramrom_Silo_1:
.incbin "assets/ramrom/ramrom_Silo_1.bin"
ramrom_Silo_1_end:

.global ramrom_Silo_2
ramrom_Silo_2:
.incbin "assets/ramrom/ramrom_Silo_2.bin"
ramrom_Silo_2_end:

.global ramrom_Frigate_1
ramrom_Frigate_1:
.incbin "assets/ramrom/ramrom_Frigate_1.bin"
ramrom_Frigate_1_end:

.global ramrom_Frigate_2
ramrom_Frigate_2:
.incbin "assets/ramrom/ramrom_Frigate_2.bin"
ramrom_Frigate_2_end:

.global ramrom_Train
ramrom_Train:
.incbin "assets/ramrom/ramrom_Train.bin"
ramrom_Train_end:

.endif
