insideCircle :: (Floating a) => (Ord a) => (a, a) -> a -> (a, a) -> Bool
insideCircle (x1, y1) r (x2, y2) = ((x1 - x2) ** 2 + (y1 - y2) ** 2) <= r * r

main = 
    do
        putStr "Center=(0,0), radius=1.5 & Point=(1,1): "
        print (insideCircle (0,0) 1.5 (1,1))
        putStr "Center=(0,0), radius=1.4 & Point=(1,1): "
        print (insideCircle (0,0) 1.4 (1,1))