<?PHP
session_start();
$login = NULL;
if ($_SESSION['loggued_on_user'] != NULL)
		$login = key($_SESSION['loggued_on_user']);
?>
<HTML>
<HEAD>
	<TITLE>Homepage</TITLE>
	<link rel="stylesheet" href="homepage.css">
</HEAD>
<BODY>
</div>
	<?PHP
	include ("header_site.php");
	?>
		<div class="left_bar" style="visibility: hidden;">
		</div>
		<div class="body_bar">
		<span style="text-align:center">
			<iframe src="https://giphy.com/embed/yjGdFXjeQsDqJNSzE4" width="360"align="left" height="203" frameBorder="0" class="giphy" allowFullScreen></iframe>
			<iframe src="https://giphy.com/embed/fItgT774J3nWw" width="360" height="203" frameBorder="0" class="giphy" allowFullScreen></iframe>
			<br /><br />
			<iframe src="https://giphy.com/embed/cLcxtL1z8t8oo" width="360" height="203" frameBorder="0" class="giphy" allowFullScreen></iframe>
			<iframe src="https://giphy.com/embed/JPayEyQPRCUTe" width="360" height="203" frameBorder="0" class="giphy" allowFullScreen></iframe>
			<br /><br />
			<iframe src="https://giphy.com/embed/6C9CMGMFtzzbO" width="360" height="203" frameBorder="0" class="giphy" allowFullScreen></iframe>
			<iframe src="https://giphy.com/embed/1LweXxLwVT0J2" width="360" height="203" frameBorder="0" class="giphy" allowFullScreen></iframe>
		</span>
		</div>
		<?php
		include ("right_bar.php");
		?>
	</div>
</ul>
</nav>
</BODY>
</HTML>
