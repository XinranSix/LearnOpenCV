add_rules("mode.debug", "mode.release")
add_requires("opencv", "fmt", "gtest")

add_includedirs("./include")

for _, filepath in ipairs(os.files("./src/**.cpp")) do
target(path.basename(filepath))
    add_files(filepath)
    add_packages("opencv", "fmt", "gtest")
    after_build(function (target)
        os.cp("assets", target:targetdir())
        os.cp("images", target:targetdir())
    end)
end
