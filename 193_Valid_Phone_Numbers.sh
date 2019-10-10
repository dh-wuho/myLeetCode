# Read from the file file.txt and output all valid phone numbers to stdout.
# only grep can accept \d
grep -P '^(\([[:digit:]]{3}\) |\d{3}-)\d{3}-\d{4}$' file.txt

# awk and sed don't recognize \d
awk '/^([[:digit:]]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/{print}' file.txt
sed -n -E '/^([[:digit:]]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt