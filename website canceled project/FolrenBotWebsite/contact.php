<?php
	$name = $_POST['name'];
	$visitor_email = $_POST['email'];
	$message = $_POST['message'];


	$email_from = "yourmail@gmail.com"; //from where to recieve (your mail (a not used one)

	$mail_subjet = "New Site Message";

	$email_body = "User name: $name.\n".
					"User email: $visitor_email.\n".
						"User message: $message.\n";


	$to = "sth@gmail.com"; // mail where u want to answer and stuff (also your mail)

	$headers = "From: $email_from \r\n";

	$headers .= "Reply-To: $visitor_email \r\n";

	mail($to,$email_subject,$email_body,$Headers);

	header("Location: contact.html");

?>