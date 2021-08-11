// Example to (un)encrypt $string

$string = 'Hey';
echo mdp($string, 'lisible');  // encrypt "Hey"

$string = 'Djoceicecoe';
echo mdp($string, 'illisible');  // unencrypt "Djoceicecoe" to "Hey"

Live version here : https://arni.fr/hash/

// Example to (un)encrypt $string with post request named "string"

echo $POST[] mdp($_POST["strin"], 'lisible');  // encrypt ""

echo mdp($string, 'illisible');  // unencrypt "Djoceicecoe" to "Hey"

