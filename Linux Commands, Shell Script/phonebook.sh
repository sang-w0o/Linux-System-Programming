
# A simple phonebook shell program

register() {
	echo " # Register Info #"
	read -p "Insert name : " name

	if [ -z "$name" ]; then
		echo "No name inserted. Press Enter to return to menu.."
		read
		return
	fi

	result=$(grep "$name" list.txt)
	if [ -n "$result" ]; then
		echo "This name already exists. Press Enter to return to menu.."
		read
		return
	fi

	read -p "Insert number : " num

	echo "$name : $num" >> list.txt
	echo "Register succeeded."
}

search() {
	echo " # Search Info #"
	read -p "Insert name : " name
	info=$(grep "$name" list.txt)
	if [ -n "$info" ]; then
		echo "$name's number is ${info#*:}"
	else
		echo "Info doesn't exist."
	fi
}

remove() {
	echo " # Remove Info #"
	read -p "Insert name : " name
	info=$(grep "$name" list.txt)
	if [[ -n "$info" ]]; then
		touch tmp.txt
		chmod 777 tmp.txt
		grep -v "$name" list.txt > tmp.txt
		rm list.txt
		mv tmp.txt list.txt
		echo "Removed."
	else
		echo "Info doesn't exist."
	fi
}

menu() {
	echo " # Phonebook Script #"
	echo "1. Register"
	echo "2. Search"
	echo "3. Remove"
	
	read -p "Insert menu number(0:quit):"
	

	case $REPLY in
		1) register;;
		2) search;;
		3) remove;;
		0) exit;;
		*) echo "Wrong menu number."exit;;
	esac
}

while true; do
	menu
done
