create database ManageShopOnline

create table Product(
	ProdID varchar(10) primary key,
	ProdName varchar(50) not null,
	ProdDescription varchar(500),
	ProdPrice money check(ProdPrice>0),
	Stock int check(Stock>0 or Stock=0)
)

	
create table Categories(
	CategID varchar(10) primary key,
	CategName varchar(50) not null,
	PordID varchar(10) foreign key references Product(ProdID),
	CategDescription varchar(500) not null
)

create table Customer(
	CustID varchar(10) primary key,
	CustName varchar(50) not null,
	CustPhone varchar(11) not null,
	CustEmail varchar(50) unique,
	CustAddress varchar(100) not null
)

create table Invoice(
	InvoiceID varchar(10) primary key,
	CustID varchar(10) foreign key references Customer(CustID),
	[Date] datetime
)

create table Invoice_Product(
	InvoiceID varchar(10) foreign key references Invoice(InvoiceID),
	ProdID varchar(10) foreign key references Product(ProdID),
	Quantity int check (Quantity>0)
)

create table Feedback(
	CustID varchar(10) foreign key references Customer(CustID),
	ProdID varchar(10) foreign key references Product(ProdID),
	Comment varchar(300) unique,
	[Date] datetime
)

create table ManageAccount(
	AccName varchar(30) not null,
	AccPass varchar(20) not null,
	AccPhone varchar(11) not null,
	AccAddress varchar(50) not null,
	AccEmail varchar(50) unique,
	[Status] varchar(20) check([Status]='activated' or [Status]='deactivated')
)

--Views
create view view_CustomersOpinion as
select Customer.* , Feedback.Comment,Feedback.Date,Feedback.ProdID
from Customer, Feedback
where Customer.CustID=Feedback.CustID



create view view_Statistics as
SELECT Customer.CustID, Customer.CustName, Invoice.InvoiceID, Invoice.Date, Customer.CustPhone, Customer.CustEmail, Invoice_Product.Quantity, Product.ProdID, Product.ProdName, Product.ProdPrice, Product.Stock
FROM Customer INNER JOIN Invoice ON Customer.CustID = Invoice.CustID 
			  INNER JOIN Invoice_Product ON Invoice.InvoiceID = Invoice_Product.InvoiceID 
			  INNER JOINProduct ON Invoice_Product.ProdID =Product.ProdID



create view view_CustomersWithAccount as
SELECT Customer.CustID, Customer.CustName, Customer.CustPhone,Customer.CustEmail, Customer.CustAddress, ManageAccount.AccName, ManageAccount.Status
FROM Customer CROSS JOIN ManageAccount
where Customer.CustEmail=ManageAccount.AccEmail or Customer.CustPhone=ManageAccount.AccPhone or Customer.CustAddress=ManageAccount.AccAddress;



create view view_InvoicesAndDetalis as
SELECT Customer.*, Invoice.Date, Invoice.InvoiceID, Invoice_Product.ProdID, Invoice_Product.Quantity
FROM Customer INNER JOIN Invoice ON Customer.CustID = Invoice.CustID 
			  INNER JOIN Invoice_Product ON Invoice.InvoiceID =Invoice_Product.InvoiceID

