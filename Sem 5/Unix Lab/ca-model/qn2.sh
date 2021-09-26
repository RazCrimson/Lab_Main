for x in "$HOME/temp/UNIX-CA"/*
do
  echo $x $(echo $x | tr "[:lower:]" "[:upper:]")
done
