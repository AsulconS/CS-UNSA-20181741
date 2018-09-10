main = do
    n <- readLn
    let a = [ x | x <- [0..(n - 1)] , ((x `mod` 3 == 0) || (x `mod` 5 == 0))]
    print(sum a)
