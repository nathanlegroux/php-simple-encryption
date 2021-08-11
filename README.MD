## Example to (un)encrypt $string


// Note : Change your hash key in function.php ( $clef )


// Encrypt 

```php
<?php

include 'function.php';

$string = 'Hey';

echo mdp($string, 'lisible');  // encrypt "Hey"

?>
```

// Unencrypt 

```php
<?php


include 'function.php';

$string = 'Djoceicecoe';

echo mdp($string, 'illisible');  // unencrypt "Djoceicecoe" to "Hey"

?>
```

## Example to (un)encrypt $string with post request named "string"

// Encrypt 

```php
<?php


include 'function.php';

echo mdp($_POST["string"], 'illisible');  // unencrypt "$_POST["string"]"

?>
```

// Unencrypt 

```php
<?php

include 'function.php';

echo mdp($_POST["string"], 'lisible');  // encrypt "$_POST["string"]"

?>
```

## Live version here : https://arni.fr/hash/

