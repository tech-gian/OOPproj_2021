# Paths
MODULES = ../modules
INCLUDE = ../include

# Compiler
CC = g++

# Compile Options
CXXFLAGS = -Wall -Werror -g -I$(INCLUDE)

# Files .o
# TODO: check that everything is written
OBJS = $(MODULES)/Grid/Grid.o $(MODULES)/Grid/Square/Common.o $(MODULES)/Grid/Square/Market.o $(MODULES)/Grid/Square/nonAccesible.o $(MODULES)/Grid/Square/Square.o $(MODULES)/Item/Item.o $(MODULES)/Item/Armor.o $(MODULES)/Item/Weapon.o $(MODULES)/Item/Potion.o $(MODULES)/Living/Living.o $(MODULES)/Living/Hero/Hero.o $(MODULES)/Living/Hero/Paladin.o $(MODULES)/Living/Hero/Sorcerer.o $(MODULES)/Living/Hero/Warrior.o $(MODULES)/Living/Monster/Monster.o $(MODULES)/Living/Monster/Dragon.o $(MODULES)/Living/Monster/Exoskeleton.o $(MODULES)/Living/Monster/Spirit.o

# Executable File
EXEC = main_game

# Arguments
ARGS = 

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) $(ARGS)
