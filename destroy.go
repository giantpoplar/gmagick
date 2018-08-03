package gmagick

// Destroyer represents destroyable types which require manual release of resources
type Destroyer interface {
	Destroy()
}

// Destroy instance of Destroyer
// If GOGC=off you should call obj.Destroy() manually
func Destroy(d Destroyer) {
	d.Destroy()
}
