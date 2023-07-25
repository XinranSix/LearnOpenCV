add_rules("mode.debug", "mode.release")
add_requires("opencv")
add_requires("fmt", "gtest")
add_requires("tbox", "zlib", "libpng","libsdl","libsdl_image")

add_includedirs("./include")

for _, filepath in ipairs(os.files("./**.cpp")) do
target(path.basename(filepath))
    add_files(filepath)
    add_packages("opencv")
    after_build(function (target)
        os.cp("assets", target:targetdir())
    end)
end
