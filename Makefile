# =========================================================
# Assignment 1: Linked Lists
# Mo Dehghani’s Code Initiative
# Language: C++
# =========================================================

language := cpp
code := $(wildcard src/*)
test_directories := $(wildcard tests/*)
test_targets := $(addsuffix /pass,$(test_directories))
existing_passes := $(wildcard tests/*/pass)
out_files := $(wildcard tests/*/*.out)
out_files += $(wildcard tests/*/out.*)

# ---------------------------------------------------------
# Formatting helpers
# ---------------------------------------------------------
define start-test =
	@export TERM=screen-256color && tput smso && tput setaf 4 && \
	echo -e "\n============= make test: $(patsubst %/pass,%/,$@) =============" && \
	tput rmso && tput sgr0
endef

define continue =
	[[ "$$IS_PIPELINE" ]] || (echo -en '\nPress `Enter` to continue:' && read)
endef

define start-section =
	@export TERM=screen-256color && tput smso && tput setaf 4 && \
	echo -e "\n============= make $@ =============" && \
	tput rmso && tput sgr0
endef

# ---------------------------------------------------------
# Targets
# ---------------------------------------------------------
.PHONY: all help prechecks build run test summary grade clean

all: # Runs full autograding pipeline
	$(start-section)
	@$(MAKE) help --no-print-directory
	@$(MAKE) clean --no-print-directory
	-@$(MAKE) test --keep-going --no-print-directory
	@$(MAKE) summary --no-print-directory
	@$(MAKE) grade --no-print-directory

help: # Show help for each Makefile target
	$(start-section)
	@echo -e "Assignment 1: Linked Lists (C++)"
	@echo -e "This autograder helps validate your linked list implementation."
	@echo -e "Do NOT rely solely on the autograder while developing."
	@echo -e "You should compile and run your program manually during development.\n"
	@grep -E '^[a-zA-Z0-9_-]+:.*#' Makefile | sort | while read -r l; \
	do tput setaf 4 && echo -en "$$(echo $$l | cut -f 1 -d':'): " && \
	tput sgr0 && echo "$$(echo $$l | cut -f 2- -d'#')"; done
	@$(continue)

# ---------------------------------------------------------
# Build & Run
# ---------------------------------------------------------
build: $(code) # Builds student linked list program only
	$(start-section)
	cd src && $(MAKE) --no-print-directory

run: build # Builds and runs program (use: make run myargs="...")
	$(start-section)
	./linkedlist $(myargs)

# ---------------------------------------------------------
# Tests
# ---------------------------------------------------------
tests/%/pass: $(code)
	$(start-test) && cd $(patsubst %/pass,%/,$@) && $(MAKE) --no-print-directory

prechecks: # Runs dependency and integrity checks
	$(start-section)
	@bash ./.admin_files/dependency_checks.sh $(language)
	@bash ./.admin_files/check_hashes.sh

test: prechecks $(test_targets) # Runs all tests
	@true

summary: # Summarize passing/failing tests
	$(start-section)
	@echo -e "Test results summary:"
	@export TERM=screen-256color && \
	for dir in tests/*; \
	do (cd "$$dir"; echo -en "$$dir -- "; \
	[ -f pass ] \
	&& (tput setaf 2 && cat pass && tput sgr0) \
	|| (tput setaf 1 && echo "failed" && tput sgr0)); done

grade: prechecks # Compute grade from passing tests
	$(start-section)
ifdef existing_passes
	@cat $(existing_passes) >scores
	@python3 -c "print(round(($$(paste --serial --delimiter=+ scores)) / $$(ls tests | wc -w)))" >grade
	@rm scores
	@echo -e "Calculated score:"
	@export TERM=screen-256color && tput smso && cat grade && tput rmso
else
	@echo "No passing tests yet. Run: make test"
	@[[ "$$IS_PIPELINE" ]] && (echo 0 >grade && exit 1)
endif

# ---------------------------------------------------------
# Cleanup
# ---------------------------------------------------------
clean: # Remove all generated files
	$(start-section)
	@rm -f $(test_targets)
	@rm -f $(out_files)
	@rm -rf build/*
	@rm -f linkedlist
	@rm -rf target/*
	@rm -rf *.out *.o *.log
	@rm -rf .gdb_history
	@rm -rf */*.out */*.o */*.log */.gdb_history
