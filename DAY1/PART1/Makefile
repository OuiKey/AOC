# Tâche par défaut : créer l'exécutable
all: build/main

# Répertoires et fichiers
PROJECTINCLUDEDIR = include/
OBJDIR = obj
LIBS = -lm
INCLUDEFLAGS = -I$(PROJECTINCLUDEDIR)
OBJ = $(patsubst %,$(OBJDIR)/%.o,$(MAINMODULES)) $(patsubst %,$(OBJDIR)/%.o,$(IHMMODULES))
MAINHEADERDEPENDANCIES = $(patsubst %,$(PROJECTINCLUDEDIR)/%.h,$(MAINMODULES))

# Créer les répertoires si nécessaires
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilation des modules principaux
MAINMODULES = main func

$(OBJDIR)/%.o: src/%.c $(MAINHEADERDEPENDANCIES) | $(OBJDIR)
	gcc -g -Wall ${INCLUDEFLAGS} -c $< -o $@
	
$(OBJDIR)/%.o: GEII_IHM/src/%.c $(IHMHEADERDEPENDANCIES) | $(OBJDIR)
	gcc -g -Wall ${INCLUDEFLAGS} -c $< -o $@

# Lien final pour l'exécutable principal
build/main: $(OBJ)
	gcc -g $(OBJ) $(LIBS) -o $@

# Nettoyage
clean:
	rm -rf obj/*.o build/main build/tests

# Démarrer le programme
r: build/main
	./build/main

# Nettoyage, compilation, et démarrage
ccr: clean all r

# Compilation et démarrage
cr: all r
