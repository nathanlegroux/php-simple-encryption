- !`Note : Change your hash key in function.php ( $clef )`


## Example to (un)encrypt $mot


// Encrypt 

```php
<?php

include 'function.php';

$mot = 'Hey';

echo mdp($mot, 'illisible');  // encrypt "Hey"

?>
```

// Unencrypt 

```php
<?php


include 'function.php';

$mot = 'Djoceicecoe';

echo mdp($mot, 'lisible');  // unencrypt "Djoceicecoe" to "Hey" ( it's an example 😆 )

?>
```

## Example to (un)encrypt a post request named "mot"

// Encrypt 

```php
<?php


include 'function.php';

echo mdp($_POST["mot"], 'illisible');  // unencrypt "$_POST["mot"]"

?>
```

// Unencrypt 

```php
<?php

include 'function.php';

echo mdp($_POST["mot"], 'lisible');  // encrypt "$_POST["mot"]"

?>
```
