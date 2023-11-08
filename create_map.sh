#Create the example file to run the bsq program
./map/gen_map.pl $1 $2 $3 > example_file;
cat example_file -e;
#./bsq example_file;
