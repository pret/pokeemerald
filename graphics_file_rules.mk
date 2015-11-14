monstillfrontdir = data/graphics/pokemon/still_front_pics
monbackdir := data/graphics/pokemon/back_pics
monfrontdir := data/graphics/pokemon/front_pics
monpaldir = data/graphics/pokemon/palettes

$(monstillfrontdir)/castform_still_front_pic.4bpp: $(monstillfrontdir)/castform_normal_form_still_front_pic.4bpp \
                                                   $(monstillfrontdir)/castform_sunny_form_still_front_pic.4bpp \
                                                   $(monstillfrontdir)/castform_rainy_form_still_front_pic.4bpp \
                                                   $(monstillfrontdir)/castform_snowy_form_still_front_pic.4bpp
	@cat $(monstillfrontdir)/castform_normal_form_still_front_pic.4bpp $(monstillfrontdir)/castform_sunny_form_still_front_pic.4bpp $(monstillfrontdir)/castform_rainy_form_still_front_pic.4bpp $(monstillfrontdir)/castform_snowy_form_still_front_pic.4bpp >$@

$(monbackdir)/castform_back_pic.4bpp: $(monbackdir)/castform_normal_form_back_pic.4bpp \
                                      $(monbackdir)/castform_sunny_form_back_pic.4bpp \
                                      $(monbackdir)/castform_rainy_form_back_pic.4bpp \
                                      $(monbackdir)/castform_snowy_form_back_pic.4bpp
	@cat $(monbackdir)/castform_normal_form_back_pic.4bpp $(monbackdir)/castform_sunny_form_back_pic.4bpp $(monbackdir)/castform_rainy_form_back_pic.4bpp $(monbackdir)/castform_snowy_form_back_pic.4bpp >$@

$(monfrontdir)/castform_front_pic.4bpp: $(monfrontdir)/castform_normal_form_front_pic.4bpp \
                                        $(monfrontdir)/castform_sunny_form_front_pic.4bpp \
                                        $(monfrontdir)/castform_rainy_form_front_pic.4bpp \
                                        $(monfrontdir)/castform_snowy_form_front_pic.4bpp
	@cat $(monfrontdir)/castform_normal_form_front_pic.4bpp $(monfrontdir)/castform_sunny_form_front_pic.4bpp $(monfrontdir)/castform_rainy_form_front_pic.4bpp $(monfrontdir)/castform_snowy_form_front_pic.4bpp >$@

$(monpaldir)/castform_palette.gbapal: $(monpaldir)/castform_normal_form_palette.gbapal \
                                      $(monpaldir)/castform_sunny_form_palette.gbapal \
                                      $(monpaldir)/castform_rainy_form_palette.gbapal \
                                      $(monpaldir)/castform_snowy_form_palette.gbapal
	@cat $(monpaldir)/castform_normal_form_palette.gbapal $(monpaldir)/castform_sunny_form_palette.gbapal $(monpaldir)/castform_rainy_form_palette.gbapal $(monpaldir)/castform_snowy_form_palette.gbapal >$@

$(monpaldir)/castform_shiny_palette.gbapal: $(monpaldir)/castform_normal_form_shiny_palette.gbapal \
                                            $(monpaldir)/castform_sunny_form_shiny_palette.gbapal \
                                            $(monpaldir)/castform_rainy_form_shiny_palette.gbapal \
                                            $(monpaldir)/castform_snowy_form_shiny_palette.gbapal
	@cat $(monpaldir)/castform_normal_form_shiny_palette.gbapal $(monpaldir)/castform_sunny_form_shiny_palette.gbapal $(monpaldir)/castform_rainy_form_shiny_palette.gbapal $(monpaldir)/castform_snowy_form_shiny_palette.gbapal >$@
