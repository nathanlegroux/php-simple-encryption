<?php
	function randomColor(){
		$rcolor = '#';
		for($i=0;$i<6;$i++){
		$rNumber = rand(0,15);
		switch ($rNumber) {
		case 10:$rNumber='A';
		break;
		case 11:$rNumber='B';
		break;
		case 12:$rNumber='C';
		break;
		case 13:$rNumber='D';
		break;
		case 14:$rNumber='E';
		break;
		case 15:$rNumber='F';
		break;
	}
		$rcolor .= $rNumber;
	}
		// $rcolor = '#FF0000';
		return $rcolor;
	}
		echo '<style>
    body {
    background-color:'.randomColor().';
   
    }
    </style>';
?>


<?php



$step = $_GET['step'];
$first = 'first';
$second = 'second';
$third = 'third';


if (strpos($step, $first) !== false) {

  $num = str_replace("first","",$_GET['step']);

  $json = file_get_contents("json.json");
  $arr = json_decode($json, true);
  
  
  
  
  $description = $arr["articles"][$num]["description"];
  $lien = $arr["articles"][$num]["url"];
  if (empty($arr["articles"][$num]["urlToImage"])) {
      $title = $arr["articles"][$num]["title"];
      $image = "base.png";
    } else {
      $title = $arr["articles"][$num]["title"];
      $image = $arr["articles"][$num]["urlToImage"];
    }
  
  
  
    ?><!DOCTYPE html>
  <html>
    
  <head>
  <link rel="apple-touch-icon" type="image/png" href="https://cpwebassets.codepen.io/assets/favicon/apple-touch-icon-5ae1a0698dcc2402e9712f7d01ed509a57814f994c660df9f7a952f3060705ee.png">
  <meta name="apple-mobile-web-app-title" content="CodePen">
  
  <link rel="shortcut icon" type="image/x-icon" href="https://cpwebassets.codepen.io/assets/favicon/favicon-aec34940fbc1a6e787974dcd360f2c6b63348d4b1f4e06c77743096d55480f33.ico">
  
  <link rel="mask-icon" type="image/x-icon" href="https://cpwebassets.codepen.io/assets/favicon/logo-pin-8f3771b1072e3c38bd662872f6b673a722f4b3ca2421637d5596661b4e2132cc.svg" color="#111">
  
  
    <title>Nathan</title>
    
    
  
      <script src=
  "https://cdn.jsdelivr.net/npm/html2canvas@1.0.0-rc.5/dist/html2canvas.min.js">
      </script>
      <script>
    if (document.location.search.match(/type=embed/gi)) {
      window.parent.postMessage("resize", "*");
    }
  </script>




    <script src="https://unpkg.com/vue@2/dist/vue.js"></script>
  <style type="text/css">@import url("https://fonts.googleapis.com/css2?family=Open+Sans&family=Poppins:wght@700&display=swap");
  :root {
    --white: white;
    --grey-500: #c8d0e7;
    --primary-300: #0094e8;
    --primary-200: #0184ce;
    --shadow-1: rgba(0, 0, 0, 0.1) 0px 4px 12px;
    --shadow-2: rgba(0, 0, 0, 0.1) 0px 4px 12px;
    --font-primary: "Poppins", sans-serif;
    --font-secondary: "Open Sans", sans-serif;
  }
  * {
    margin: 0;
    padding: 0;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
  }
  body {
    margin: 2em;

 


  }
  ul {
    list-style: none;
    display: flex;
    flex-wrap: wrap;
    grid-gap: 2em;
    justify-content: center;
  }
  .card {
    width: 512px;
    height: 512px;
    background: #fff;
    box-shadow: var(--shadow-2);
    border-radius: 8px;
    overflow: hidden;
    display: grid;
    grid-template-areas: "image" "content";
    grid-template-rows: 200px 1fr;
  }
  .card .content {
    display: grid;
    grid-template-areas: "title" "description" "footer";
    margin: 2em;
    grid-gap: 8px;
  }
  .card h3 {
    font-family: var(--font-primary);
    font-weight: 700;
    color: #333;
    font-size: 2em;
    grid-area: title;
    line-height: 1.2em;
  }
  .card p {
    font-family: var(--font-secondary);
    font-weight: 400;
    color: #555;
    font-size: 1em;
    grid-area: description;
    margin-bottom: 1em;
  }
  .card .footer {
    grid-area: footer;
    display: grid;
    grid-template-areas: "author button";
    grid-template-columns: 1fr max-content;
    align-items: end;
  }
  .card .author {
    display: flex;
    align-items: center;
  }
  .card .author img {
    width: 48px;
    height: 48px;
    border-radius: 100%;
  }
  .card .author span {
    font-family: var(--font-secondary);
    font-weight: 400;
    color: #555;
    margin-left: 0.5em;
  }
  .card img {
    object-fit: cover;
    width: 100%;
    height: 100%;
  }
  .button {
    letter-spacing: -0.5px;
    font-family: var(--font-secondary);
    font-weight: 400;
    border-radius: 100px;
    background: var(--white);
    border: 0;
    border: 1px solid #777;
    padding: 8px 12px;
    color: #333;
    width: max-content;
    cursor: pointer;
    transition: border 250ms ease-in-out;
    height: max-content;
  }
  .button:hover {
    border: 1px solid var(--primary-300);
  }
  .button:active {
    border: 1px solid var(--primary-200);
  }
  
  </style>
  
  </head>
    
  <body>
  
      <div id="app"><ul><li><div class="card"><img src="<?php echo $image ?>" alt="random photo"> <div class="content"> 
      <?php
      
      if (isset($_GET["description"])) { ?>
          <div class="author"> <span><?php echo $description; ?></span></div>
          <div class="author"> <span><?php echo $lien; ?></span></div>
  <?php } else { ?> <h3>
    <?php
echo mb_strimwidth($title, 0, 100, "...");
//Hello W...
?>

 </h3><?php
   
    } 
  
    ?>
  
   
      <div class="footer"><div class="author"> <span>TheLight.speak</span></div> <button class="button button--primary"><?php echo date("d/m"); ?></button></div></div></div></li></ul></div>
    
      </div>
  
     
  
  <script src="https://cpwebassets.codepen.io/assets/common/stopExecutionOnTimeout-1b93190375e9ccc259df3a57c1abc0e64599724ae30d7ea4c6877eb615f89387.js"></script>
  
    
    
  
  <script type="module">
    import CodePenVueComponent from "/ArranGravestock/pen/ExWKoOp.js";
  
    var app = new Vue(CodePenVueComponent).$mount('#app');
    Vue.config.devtools = true; /* Ensuring Dev Tools is enabled. */
  </script>
  
  
  </body>
    
  </html>
  
  <?php } 

if (strpos($step, $second) !== false) {


  $json = file_get_contents("http://localhost/json.json");
  $arr = json_decode($json, true);
  $num = str_replace("second","",$_GET['step']);
  $description = $arr["articles"][$num]["description"];
  $lien = $arr["articles"][$num]["url"];
  if (empty($arr["articles"][$num]["urlToImage"])) {
      $title = $arr["articles"][$num]["title"];
      $image = "https://mir-s3-cdn-cf.behance.net/project_modules/1400/4d845686128681.5d909dad4ddd3.jpg";
    } else {
      $title = $arr["articles"][$num]["title"];
      $image = $arr["articles"][$num]["urlToImage"];
    }
  
  
  
    ?>
    
    <!DOCTYPE html>
  <html>
    
  <head>
  <link rel="apple-touch-icon" type="image/png" href="https://cpwebassets.codepen.io/assets/favicon/apple-touch-icon-5ae1a0698dcc2402e9712f7d01ed509a57814f994c660df9f7a952f3060705ee.png">
  <meta name="apple-mobile-web-app-title" content="CodePen">
  
  <link rel="shortcut icon" type="image/x-icon" href="https://cpwebassets.codepen.io/assets/favicon/favicon-aec34940fbc1a6e787974dcd360f2c6b63348d4b1f4e06c77743096d55480f33.ico">
  
  <link rel="mask-icon" type="image/x-icon" href="https://cpwebassets.codepen.io/assets/favicon/logo-pin-8f3771b1072e3c38bd662872f6b673a722f4b3ca2421637d5596661b4e2132cc.svg" color="#111">
  
  
    <title>CodePen - Vue 2 Cards</title>
    
    
  
      <script src=
  "https://cdn.jsdelivr.net/npm/html2canvas@1.0.0-rc.5/dist/html2canvas.min.js">
      </script>
      <script>
    if (document.location.search.match(/type=embed/gi)) {
      window.parent.postMessage("resize", "*");
    }
  </script>
  
  
    <script src="https://unpkg.com/vue@2/dist/vue.js"></script>
  <style type="text/css">@import url("https://fonts.googleapis.com/css2?family=Open+Sans&family=Poppins:wght@700&display=swap");
  :root {
    --white: white;
    --grey-500: #c8d0e7;
    --primary-300: #0094e8;
    --primary-200: #0184ce;
    --shadow-1: rgba(0, 0, 0, 0.1) 0px 4px 12px;
    --shadow-2: rgba(0, 0, 0, 0.1) 0px 4px 12px;
    --font-primary: "Poppins", sans-serif;
    --font-secondary: "Open Sans", sans-serif;
  }
  * {
    margin: 0;
    padding: 0;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
  }
  body {
    margin: 2em;

 


  }
  ul {
    list-style: none;
    display: flex;
    flex-wrap: wrap;
    grid-gap: 2em;
    justify-content: center;
  }
  .card {
    width: 512px;
    height: 512px;
    background: #fff;
    box-shadow: var(--shadow-2);
    border-radius: 8px;
    overflow: hidden;
    display: grid;
    grid-template-areas: "image" "content";
    grid-template-rows: 200px 1fr;
  }
  .card .content {
    display: grid;
    grid-template-areas: "title" "description" "footer";
    margin: 2em;
    grid-gap: 8px;
  }
  .card h3 {
    font-family: var(--font-primary);
    font-weight: 700;
    color: #333;
    font-size: 2em;
    grid-area: title;
    line-height: 1.2em;
  }
  .card p {
    font-family: var(--font-secondary);
    font-weight: 400;
    color: #555;
    font-size: 1em;
    grid-area: description;
    margin-bottom: 1em;
  }
  .card .footer {
    grid-area: footer;
    display: grid;
    grid-template-areas: "author button";
    grid-template-columns: 1fr max-content;
    align-items: end;
  }
  .card .author {
    display: flex;
    align-items: center;
  }
  .card .author img {
    width: 48px;
    height: 48px;
    border-radius: 100%;
  }
  .card .author span {
    font-family: var(--font-secondary);
    font-weight: 400;
    color: #555;
    margin-left: 0.5em;
  }
  .card img {
    object-fit: cover;
    width: 100%;
    height: 100%;
  }
  .button {
    letter-spacing: -0.5px;
    font-family: var(--font-secondary);
    font-weight: 400;
    border-radius: 100px;
    background: var(--white);
    border: 0;
    border: 1px solid #777;
    padding: 8px 12px;
    color: #333;
    width: max-content;
    cursor: pointer;
    transition: border 250ms ease-in-out;
    height: max-content;
  }
  .button:hover {
    border: 1px solid var(--primary-300);
  }
  .button:active {
    border: 1px solid var(--primary-200);
  }
  
  </style>
  
  </head>
    
  <body>
  
      <div id="app"><ul><li><div class="card"><img src="<?php echo $image ?>" alt="error"> <div class="content"> 
   
          <div class="author"> <span><?php echo $description; ?></span></div>
  
  
  
   
      <div class="footer"><div class="author"> <span>TheLight.speak</span></div> <button class="button button--primary"><?php echo date("d/m"); ?></button></div></div></div></li></ul></div>
    
      </div>
  
     
  
  <script src="https://cpwebassets.codepen.io/assets/common/stopExecutionOnTimeout-1b93190375e9ccc259df3a57c1abc0e64599724ae30d7ea4c6877eb615f89387.js"></script>
  
    
    
  
  <script type="module">
    import CodePenVueComponent from "/ArranGravestock/pen/ExWKoOp.js";
  
    var app = new Vue(CodePenVueComponent).$mount('#app');
    Vue.config.devtools = true; /* Ensuring Dev Tools is enabled. */
  </script>
  
  
  </body>
    
  </html>


  <?php } 

if (strpos($step, $third) !== false) {
 
$json = file_get_contents("http://localhost/json.json");
$arr = json_decode($json, true);
$num = str_replace("third","",$_GET['step']);
$description = $arr["articles"][$num]["description"];
$lien = $arr["articles"][$num]["url"];
if (empty($arr["articles"][$num]["urlToImage"])) {
    $title = $arr["articles"][$num]["title"];
    $image = "https://mir-s3-cdn-cf.behance.net/project_modules/1400/4d845686128681.5d909dad4ddd3.jpg";
  } else {
    $title = $arr["articles"][$num]["title"];
    $image = $arr["articles"][$num]["urlToImage"];
  }



  ?><!DOCTYPE html>
<html>
  
<head>
<link rel="apple-touch-icon" type="image/png" href="https://cpwebassets.codepen.io/assets/favicon/apple-touch-icon-5ae1a0698dcc2402e9712f7d01ed509a57814f994c660df9f7a952f3060705ee.png">
<meta name="apple-mobile-web-app-title" content="CodePen">

<link rel="shortcut icon" type="image/x-icon" href="https://cpwebassets.codepen.io/assets/favicon/favicon-aec34940fbc1a6e787974dcd360f2c6b63348d4b1f4e06c77743096d55480f33.ico">

<link rel="mask-icon" type="image/x-icon" href="https://cpwebassets.codepen.io/assets/favicon/logo-pin-8f3771b1072e3c38bd662872f6b673a722f4b3ca2421637d5596661b4e2132cc.svg" color="#111">


  <title>CodePen - Vue 2 Cards</title>
  
  

    <script src=
"https://cdn.jsdelivr.net/npm/html2canvas@1.0.0-rc.5/dist/html2canvas.min.js">
    </script>
    <script>
  if (document.location.search.match(/type=embed/gi)) {
    window.parent.postMessage("resize", "*");
  }
</script>


  <script src="https://unpkg.com/vue@2/dist/vue.js"></script>
<style type="text/css">@import url("https://fonts.googleapis.com/css2?family=Open+Sans&family=Poppins:wght@700&display=swap");
:root {
  --white: white;
  --grey-500: #c8d0e7;
  --primary-300: #0094e8;
  --primary-200: #0184ce;
  --shadow-1: rgba(0, 0, 0, 0.1) 0px 4px 12px;
  --shadow-2: rgba(0, 0, 0, 0.1) 0px 4px 12px;
  --font-primary: "Poppins", sans-serif;
  --font-secondary: "Open Sans", sans-serif;
}
* {
  margin: 0;
  padding: 0;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
}
body {
    margin: 2em;

 


  }
  ul {
    list-style: none;
    display: flex;
    flex-wrap: wrap;
    grid-gap: 2em;
    justify-content: center;
  }
  .card {
    width: 512px;
    height: 512px;
    background: #fff;
    box-shadow: var(--shadow-2);
    border-radius: 8px;
    overflow: hidden;
    display: grid;
    grid-template-areas: "image" "content";
    grid-template-rows: 200px 1fr;
  }
.card .content {
  display: grid;
  grid-template-areas: "title" "description" "footer";
  margin: 2em;
  grid-gap: 8px;
}
.card h3 {
  font-family: var(--font-primary);
  font-weight: 700;
  color: #333;
  font-size: 2em;
  grid-area: title;
  line-height: 1.2em;
}
.card p {
  font-family: var(--font-secondary);
  font-weight: 400;
  color: #555;
  font-size: 1em;
  grid-area: description;
  margin-bottom: 1em;
}
.card .footer {
  grid-area: footer;
  display: grid;
  grid-template-areas: "author button";
  grid-template-columns: 1fr max-content;
  align-items: end;
}
.card .author {
  display: flex;
  align-items: center;
}
.card .author img {
  width: 250px;
  height: 250px;
  display: block;
  margin-left: auto;
  margin-right: auto;
}
.card .author span {
  font-family: var(--font-secondary);
  font-weight: 400;
  color: #555;
  margin-left: 0.5em;
}
.card img {
  object-fit: cover;
  width: 100%;
  height: 100%;
}
.button {
  letter-spacing: -0.5px;
  font-family: var(--font-secondary);
  font-weight: 400;
  border-radius: 100px;
  background: var(--white);
  border: 0;
  border: 1px solid #777;
  padding: 8px 12px;
  color: #333;
  width: max-content;
  cursor: pointer;
  transition: border 250ms ease-in-out;
  height: max-content;
}
.button:hover {
  border: 1px solid var(--primary-300);
}
.button:active {
  border: 1px solid var(--primary-200);
}

</style>

</head>
  
<body>

    <div id="app"><ul><li><div class="card"><img src="<?php echo $image ?>" alt="random photo"> <div class="content"> 
 
        <div class="author"> <span>L'article est disponible ici !</span></div>
        <div class="author">         <img src="https://chart.googleapis.com/chart?chs=250x250&cht=qr&chl=<?php echo $lien ?>"></div>




    </div>

   

<script src="https://cpwebassets.codepen.io/assets/common/stopExecutionOnTimeout-1b93190375e9ccc259df3a57c1abc0e64599724ae30d7ea4c6877eb615f89387.js"></script>

  
  

<script type="module">
  import CodePenVueComponent from "/ArranGravestock/pen/ExWKoOp.js";

  var app = new Vue(CodePenVueComponent).$mount('#app');
  Vue.config.devtools = true; /* Ensuring Dev Tools is enabled. */
</script>


</body>
  
</html>



<?php } ?>



