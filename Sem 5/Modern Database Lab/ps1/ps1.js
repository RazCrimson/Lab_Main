// use modern_db_ps1;

// QN 1
db.publishers.find();

// QN 2
db.books.find({title: "Database and its quirks"});

// QN 3
db.books.find().sort({rating: -1}).limit(3);

// QN 4
db.books.find({"authors.author_name": "Abraham silberschatz"});

// QN 5
db.books.find({"authors.author_country": "India"}).sort({title: 1});

// QN 6
db.publishers.updateOne(
    {name: "Prentice Hall"},
    {$inc: {annual_revenue: 1000}}
);

// QN 7
db.books.find({
    title: {$regex: "database", $options: "i"},
    price: {$lt: 500},
});

// QN 8
db.books.find({category: {$in: ["Math", "Biology"]}}).sort({title: 1});

// QN 9
db.books.aggregate([
    {$unwind: "$authors"},
    {$match: {"authors.author_country": "India"}},
    {
        $project: {
            author_name: "$authors.author_name",
            author_contact_no: "$authors.author_contact_no",
            title: 1,
            _id: 0,
        },
    },
]);

// QN 10
db.books.find({"authors.0.author_name": "Abraham silberschatz"});

// QN 11
db.books.find(
    {year: {$gt: 2000}},
    {title: 1, edition: 1, price: 1, _id: 0}
);

// QN 12
db.books.find({rating: {$gt: 3}}).count();

// QN 13
db.books.aggregate([
    {$unwind: "$authors"},
    {
        $group: {
            _id: "$authors.author_id",
            author_name: {$last: "$authors.author_name"},
            books_count: {$sum: 1},
            workplace: {$last: "$authors.author_country"},
        },
    },
    {$project: {_id: 0}}
]);

// QN 14
db.books.aggregate([
    {
        $lookup: {
            from: "publishers",
            localField: "publisher_id",
            foreignField: "publisher_id",
            as: "publisher_details",
        },
    },
    {$match: {title: "Database system concepts"}},
    {$project: {publisher_details: 1}},
]);

// QN 15
db.books.find({title: {$regex: "data", $options: "i"}});

// QN 16
db.books.find({price: {$gt: 1000}, rating: {$gt: 3}});

// QN 17
db.publishers.aggregate([
    {$match: {"address.city": "Delhi"}},
    {
        $group: {
            _id: "$address.city",
            Total_Revenue: {$sum: "$annual_revenue"},
        },
    },
]);

// QN 18
db.publishers.aggregate([
    {
        $lookup: {
            from: "books",
            localField: "publisher_id",
            foreignField: "publisher_id",
            as: "books",
        },
    },
    {$addFields: {total_books: {$size: "$books"}}},
    {$project: {books: 0}},
]);
