data Course = Course
  { courseNumber :: Int,
    section :: String,
    title :: String,
    instructor :: String,
    units :: Float
  }
  deriving (Show)

fetchCourseByNumber :: Int -> [Course] -> [Course]
fetchCourseByNumber num courses = [course | course <- courses, courseNumber course == num]

main :: IO ()
main = do
  let x = [Course {courseNumber = 161, section = "A", title = "Computer Science 1", instructor = "Xi Chen", units = 1.0}, Course {courseNumber = 161, section = "B", title = "Computer Science 1", instructor = "David Chio", units = 1.0}, Course {courseNumber = 261, section = "A", title = "Computer Science 2", instructor = "Henry Walker", units = 1.0}, Course {courseNumber = 262, section = "A", title = "Computer Science 2", instructor = "Brad Richards", units = 1.0}]
  putStr "All Records:\n"
  mapM_ print x
  putStr "\nFetching Records number 161:\n"
  let res = fetchCourseByNumber 161 x
  mapM_ print res
