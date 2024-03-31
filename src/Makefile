# use MinGW (gcc 6.3.0)

IMAGES = sprites.o bg_summer.o bg_autumn.o bg_winter.o bg_night.o
OBJS = ssp3droadgl.o render.o settings.o resource.o $(IMAGES)

all: ssp3droadgl.scr

ssp3droadgl.scr: $(OBJS)
	g++ -o $@ $(OBJS) -static -lstdc++ -lgcc -lscrnsave -lopengl32 -lglu32 -lgdi32 -lcomctl32 -lshlwapi -lwinmm -mwindows

ssp3droadgl.o: ssp3droadgl.cpp render.h settings.h
	g++ -o $@ -c $<

render.o: render.cpp render.h settings.h glbitmfont.h
	g++ -o $@ -c $<

settings.o: settings.cpp settings.h resource.h
	g++ -o $@ -c $<

resource.o: resource.rc resource.h icon.ico
	windres $< $@

%.o: %.png
	ld -r -b binary -o $@ $<
#	objcopy -I binary -O elf32-i386 -B i386 $< $@

%.o: %.jpg
	ld -r -b binary -o $@ $<
#	objcopy -I binary -O elf32-i386 -B i386 $< $@

.PHONY: cleanall
cleanall:
	rm -f *.scr *.o

.PHONY: clean
clean:
	rm -f *.o
