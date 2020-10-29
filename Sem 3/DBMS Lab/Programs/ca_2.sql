# QN 2 for CA 2
create database if not exists exam08;

use exam08;

# Table Definitions
CREATE TABLE Customer
(
    CusomerId    VARCHAR(20),
    CustomerName VARCHAR(30),
    DateOfBirth  DATE,
    Gender       CHAR,
    City         VARCHAR(30),
    CONSTRAINT cusomerId_pk PRIMARY KEY (CusomerId),
    CONSTRAINT cusomerId_check CHECK ( CusomerId LIKE 'C%'),
    CONSTRAINT customerName_unique UNIQUE (CustomerName),
    CONSTRAINT customerName_check CHECK ( CustomerName REGEXP '^[A-Z ]+$'),
    CONSTRAINT dateOfBirth_check CHECK ( YEAR(DateOfBirth) > 1970 ),
    CONSTRAINT gender_check CHECK ( Gender IN ('M', 'F') ),
    CONSTRAINT city_check CHECK ( City REGEXP '^[A-Z]')

);

CREATE TABLE Loan
(
    LoanId         VARCHAR(20),
    LoanName       VARCHAR(30),
    Amount         NUMERIC(8),
    RateOfInterest NUMERIC(2),
    NoOfYears      NUMERIC(4),
    CONSTRAINT loanId_pk PRIMARY KEY (LoanId),
    CONSTRAINT loanId_check CHECK ( LOANID LIKE 'L%'),
    CONSTRAINT loanName_check CHECK ( LoanName IN ('EL', 'PL', 'HL')),
    CONSTRAINT amount_check CHECK ( Amount BETWEEN 100000 AND 500000)
    # CONSTRAINT noOfYears_check CHECK ( NoOfYears REGEXP '^[A-Z]')
    # This is a wrong constraint, but will work in MySQL 5.7 because checks are ignored

);

CREATE TABLE Transaction
(
    LoanId         VARCHAR(20) REFERENCES Loan (LoanId),
    CusomerId      VARCHAR(20) REFERENCES Customer (CusomerId),
    DateOfPurchase DATE,
    CONSTRAINT DateOfPurchase_check CHECK (YEAR(DateOfPurchase) BETWEEN 2001 AND 2008),
    PRIMARY KEY (LoanId, CusomerId)
);


# Data insertions
INSERT INTO Customer
VALUES ('C001', 'AMUDHA', STR_TO_DATE('02/12/1980', '%d/%m/%Y'), 'F', 'Cbe'),
       ('C002', 'ANUSHNA', STR_TO_DATE('12/04/1977', '%d/%m/%Y'), 'F', 'Chenni'),
       ('C003', 'VISHNU', STR_TO_DATE('10/10/2001', '%d/%m/%Y'), 'M', 'Cbe'),
       ('C004', 'NISHANTH', STR_TO_DATE('01/05/2000', '%d/%m/%Y'), 'M', 'Bombay'),
       ('C005', 'VISHVANTH', STR_TO_DATE('01/05/2004', '%d/%m/%Y'), 'M', 'Bombay');


INSERT INTO Loan
VALUES ('L01', 'EL', 100000, 10, 5),
       ('L02', 'PL', 200000, 12, 7),
       ('L03', 'HL', 500000, 15, 10);

INSERT INTO Transaction
VALUES ('L01', 'C001', STR_TO_DATE('10/10/2001', '%d/%m/%Y')),
       ('L03', 'C001', STR_TO_DATE('10/11/2001', '%d/%m/%Y')),
       ('L02', 'C003', STR_TO_DATE('19/10/2001', '%d/%m/%Y')),
       ('L03', 'C003', STR_TO_DATE('29/01/2002', '%d/%m/%Y')),
       ('L01', 'C003', STR_TO_DATE('09/10/2003', '%d/%m/%Y')),
       ('L01', 'C004', STR_TO_DATE('11/11/2003', '%d/%m/%Y')),
       ('L02', 'C005', STR_TO_DATE('14/12/2004', '%d/%m/%Y')),
       ('L03', 'C005', STR_TO_DATE('18/01/2005', '%d/%m/%Y')),
       ('L01', 'C005', STR_TO_DATE('13/11/2006', '%d/%m/%Y'));


# QN 1
SELECT CusomerId, CustomerName, Amount, NoOfYears
FROM Customer
         INNER JOIN Transaction USING (CusomerId)
         INNER JOIN Loan USING (LoanId);

# QN 2
SELECT LoanId, CustomerName
FROM Customer
         INNER JOIN Transaction USING (CusomerId)
         INNER JOIN Loan USING (LoanId)
WHERE City IN (SELECT City FROM Customer WHERE CusomerId = 'C001');

# QN 3
SELECT CusomerId, CustomerName
FROM Customer
WHERE CusomerId NOT IN (SELECT DISTINCT CusomerId FROM Transaction);

# QN 4
SELECT CustomerName, COUNT(LoanId)
FROM Customer
         INNER JOIN Transaction USING (CusomerId)
GROUP BY CustomerName
HAVING COUNT(LoanId) = (SELECT COUNT(LoanId)
                        FROM Customer
                                 INNER JOIN Transaction USING (CusomerId)
                        GROUP BY CustomerName
                        ORDER BY COUNT(LoanId) DESC
                        LIMIT 1);

# QN 5
ALTER TABLE Customer
    ADD COLUMN TOTAL NUMERIC(10) DEFAULT 0;

UPDATE Customer C SET TOTAL = (
    SELECT SUM(AMOUNT)
    FROM Transaction
     INNER JOIN Loan USING (LoanId)
    WHERE CusomerId = C.CusomerId
    GROUP BY CusomerId
) WHERE CusomerId = C.CusomerId;


# QN 6
SELECT CusomerId, CustomerName, TIMESTAMPDIFF(YEAR, DateOfBirth, CURRENT_DATE) AS Age
FROM Customer
where CusomerId IN (SELECT CusomerId FROM Transaction)
  AND DateOfBirth = (SELECT MAX(DateOfBirth) FROM Customer);