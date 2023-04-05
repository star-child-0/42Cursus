clear
echo "Signing out..."

git add --all > /dev/null 2>&1
git commit -m "See you space cowboy." > /dev/null 2>&1
git push origin master > /dev/null 2>&1

echo "See you space cowboy."
exit 0
