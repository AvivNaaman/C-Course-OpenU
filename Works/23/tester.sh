#!/usr/bin/bash
#
# Tester for mmn 23 2020b by @AvivNaaman
# To run this tester:
#    1. open terminal in the project folder, and make sure the tester is also positioned there.
#    2. run: chmod +x tester.sh
#    3. run: ./tester.sh
# NOTICE! this script is basically input file for terminal.
## This tester was not fully tested on a linux virtual machine YET.

BLUE='\e[34m'
GREEN='\e[32m'
RED='\e[31m'
BOLD='\e[1m'
RESET='\e[0m'

clear

# single valid argument
echo -e "${BLUE}${BOLD}>>> Here are all the number from 0-99 in words:${RESET}"

set -o xtrace
./numbers allnums_in
set +o xtrace

# two valid arguments
echo -e "${BLUE}${BOLD}>>> Now let's save this numbers to the file allnums_out...${RESET}"
set -o xtrace
./numbers allnums_in allnums_out
set +o xtrace
echo -e "${GREEN}${BOLD}>>> Executed. ${RESET}"
echo -e "${BLUE}>>> And let's view the contents of allnums_out:${RESET}"
cat allnums_out

echo -e "${BLUE}${BOLD}>>> Now let's test some edge cases. ${RESET}"
echo -e "${RED}${BOLD}>>> This part will not run well on NOT 100% linux machines:${RESET}"
echo -e "${BLUE}${BOLD}>>> Creating files and removing access to them:${RESET}"
# read/write to file that you have no access to:
touch ".denied_f0"
touch ".denied_f1"
chmod u-rw ".denied_f0" # deny
chmod u-rw ".denied_f1" # deny
echo -e "${GREEN}${BOLD}>>> Done! ${RESET}"
echo -e "${RED}${BOLD}>>> Running your program with both denied files as arguments:${RESET}"
set -o xtrace
./numbers allnums_in .denied_f1
./numbers allnums_in .denied_f0
set +o xtrace
# give permissions and try to clean up
chmod +rwx ".denied_f0" # allow
chmod +rwx ".denied_f1" # allow
rm -rf .denied_f* # delete

# file that doesn't exist
echo -e "${BLUE}${BOLD}>>> Now file that doesn't exist:${RESET}"
set -o xtrace
./numbers SomeUnkownFile
set +o xtrace


echo -e "${GREEN}${BOLD}Goodbye! Read the output and make sure everything works fine.${RESET}"
