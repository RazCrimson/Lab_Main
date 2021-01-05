use exam168;


# TABLE DEFINITIONS
CREATE TABLE IF NOT EXISTS Company
(
    cid     VARCHAR(4),
    name    VARCHAR(20) NOT NULL,
    country VARCHAR(10),
    CONSTRAINT cid_primary_key PRIMARY KEY (cid),
    CONSTRAINT cid_check CHECK (cid LIKE 'C%'),
    CONSTRAINT name_check CHECK (UPPER(name) = name AND LENGTH(NAME) <= 8),
    CONSTRAINT country_check CHECK (country IN ('US', 'India', 'Korea', 'Japan'))
);

CREATE TABLE IF NOT EXISTS Product
(
    pid        VARCHAR(5),
    name       VARCHAR(20) NOT NULL,
    unit_price NUMERIC(8, 2),
    category   VARCHAR(10),
    cid        VARCHAR(4),
    CONSTRAINT pid_primary_key PRIMARY KEY (pid),
    CONSTRAINT pid_constraint CHECK ( pid REGEXP '^P[0-9]{4}'),
    CONSTRAINT category_constraint CHECK ( category IN ('Stationary', 'Fruit', 'Grocery')),
    CONSTRAINT cid_foreign_key FOREIGN KEY (cid) REFERENCES Company (cid)
);

CREATE TABLE IF NOT EXISTS Person
(
    pssn         VARCHAR(5),
    name         VARCHAR(20) NOT NULL,
    phone_number NUMERIC(6) UNIQUE,
    city         VARCHAR(15),
    CONSTRAINT pssn_primary_key PRIMARY KEY (pssn),
    CONSTRAINT pssn_constraint CHECK ( pssn REGEXP '^SS[0-9]{3}'),
    CONSTRAINT phone_check CHECK ( LENGTH(phone_number) = 6 )

);

CREATE TABLE IF NOT EXISTS Purchase
(
    ssn      VARCHAR(5),
    pid      VARCHAR(5),
    Quantity INTEGER,
    FOREIGN KEY (ssn) REFERENCES Person (pssn),
    FOREIGN KEY (pid) REFERENCES Product (pid),
    CONSTRAINT qty_check CHECK ( Quantity > 0 )
);

#  INSERTS
INSERT INTO Company
VALUES ('C501', 'PRATHAP', 'US'),
       ('C502', 'SANDAL', 'India'),
       ('C507', 'HERBERT', 'Korea'),
       ('C510', 'SOMAS', 'India'),
       ('C506', 'NIMBU', 'Japan');

INSERT INTO Product
VALUES ('P1001', 'Pen', 10.50, 'Stationary', 'C507'),
       ('P1002', 'Pencil', 2.50, 'Stationary', 'C501'),
       ('P1003', 'Apple', 15.50, 'Fruit', 'C502'),
       ('P1004', 'Rice', 20.50, 'Grocery', 'C501'),
       ('P1005', 'Biscuit', 20.00, 'Grocery', 'C502'),
       ('P1006', 'Orange', 5.25, 'Fruit', 'C510');

INSERT INTO Person
VALUES ('SS200', 'John', 234562, 'Chennai'),
       ('SS205', 'David', 467892, 'Cincinatti'),
       ('SS300', 'George', 378940, 'Coimbatore'),
       ('SS350', 'Joseph', 678943, 'Chennai'),
       ('SS351', 'Dravid', 789543, 'Cincinatti');

INSERT INTO Purchase
VALUES ('SS200', 'P1003', 5),
       ('SS200', 'P1005', 4),
       ('SS205', 'P1001', 2),
       ('SS205', 'P1003', 6),
       ('SS205', 'P1004', 8),
       ('SS300', 'P1004', 3),
       ('SS300', 'P1005', 2),
       ('SS300', 'P1002', 8);


# QN 1
SELECT pid AS 'Product ID', Name AS 'Product Name'
FROM Product
WHERE pid NOT IN (SELECT DISTINCT pid FROM Purchase);

# QN 2
SELECT name, SUM(Quantity)
FROM Person
         INNER JOIN Purchase ON (Person.pssn = Purchase.ssn)
GROUP BY pssn
ORDER BY pssn;

# QN 3
SELECT *
FROM Product
         INNER JOIN Purchase P USING (pid)
WHERE ssn = 'SS205';

# QN 4
SELECT Per.*
FROM Person Per
 INNER JOIN Purchase P on Per.pssn = P.ssn
GROUP BY ssn
HAVING SUM(Quantity) =(SELECT SUM(Quantity) FROM Purchase GROUP BY SSN ORDER BY SUM(Quantity) DESC LIMIT 1);

# Total_Purchase Table Creation
CREATE TABLE Total_Purchase_Price
(
    pid   VARCHAR(5),
    Price NUMERIC(10, 2),
    CONSTRAINT pid_primary_key PRIMARY KEY (pid),
    CONSTRAINT pid_foreign_key FOREIGN KEY (pid) REFERENCES Product (pid)
);


# QN 5
DELIMITER //
CREATE PROCEDURE Update_Total_Purchase_Price()
BEGIN
    DECLARE finished INTEGER DEFAULT 0;
    DECLARE u_price NUMERIC(10, 2);
    DECLARE product_id VARCHAR(5);
    DECLARE qty INTEGER;
    DECLARE productCursor CURSOR FOR SELECT pid, unit_price FROM Product;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET finished = 1;

    OPEN productCursor;

    loopProductId:
    LOOP
        FETCH productCursor INTO product_id, u_price;
        IF finished = 1 THEN
            LEAVE loopProductId;
        END IF;

        SELECT SUM(Quantity) INTO qty FROM Purchase WHERE pid = product_id;

        INSERT INTO Total_Purchase_Price VALUE (product_id, COALESCE(qty * u_price, 0))
        ON DUPLICATE KEY UPDATE Price = COALESCE(qty * u_price, 0);
    END LOOP;
END //
DELIMITER ;

# Calling Procedure & Checking Result
CALL Update_Total_Purchase_Price();
SELECT * FROM Total_Purchase_Price;


# QN 6
DELIMITER //
CREATE TRIGGER IncrementPrice
    AFTER INSERT
    ON Purchase
    FOR EACH ROW
BEGIN
    DECLARE unit_price NUMERIC(10, 2);
    DECLARE qty INTEGER;

    SELECT unit_price INTO unit_price FROM Product WHERE pid = NEW.pid;
    SELECT SUM(Quantity) INTO qty FROM Purchase WHERE pid = NEW.pid;

    UPDATE Total_Purchase_Price SET Price = COALESCE(qty * unit_price, 0) WHERE pid = NEW.pid;
    # Might better to do a Insert and switch over to duplicate when insert fails
    # as it wont throw errors when there are deletions in the table.
END //
DELIMITER ;

# Checking Before and After Trigger happens
SELECT * FROM Total_Purchase_Price;

INSERT INTO Purchase VALUE ('SS200', 'P1006', 10);

SELECT * FROM Total_Purchase_Price;
